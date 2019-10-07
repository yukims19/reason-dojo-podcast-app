/*
   Add these to your `package.json`:

   "dependencies": {
     "@apollo/react-hooks": "^3.0.1",
     "reason-apollo": "^0.17.0",
     "reason-apollo-hooks": "^2.5.1",
     "reason-react": ">=0.7.0"
   },
   "devDependencies": {
     "graphql_ppx": "^0.2.8"
   }

   Add these to your `bsconfig.json`:
   "bs-dependencies": [
     "reason-apollo-hooks",
     "reason-apollo",
     "reason-react"
   ],
   "ppx-flags": [
     "graphql_ppx/ppx"
   ]
 */

/* A helper for pretty-stringifying results */
[@bs.val]
external prettyStringify: ('a, Js.Nullable.t(unit), int) => string =
  "JSON.stringify";

let appId = "f5114691-90b4-4746-9375-4f329499ae5c";

module Client = {
  /* Create an InMemoryCache */
  let inMemoryCache = ApolloInMemoryCache.createInMemoryCache();

  /* Create an HTTP Link */
  let httpLink =
    ApolloLinks.createHttpLink(
      ~uri="https://serve.onegraph.com/graphql?app_id=" ++ appId,
      (),
    );

  let client =
    ReasonApollo.createApolloClient(~link=httpLink, ~cache=inMemoryCache, ());

  let authConfig =
    OneGraphAuth.createOptions(
      ~appId,
      ~oneGraphOrigin="https://serve.onegraph.io",
      (),
    );

  let auth = OneGraphAuth.create(authConfig);
};

module RssFeedQueryConfig = [%graphql
  {|
  query RssFeed($url: String!) {
    rss {
      rss2Feed(url: $url) {
        title
        description
        image {
          uri
          link
          title
          width
          height
          description
        }
        items {
          title
          pubDate
          source {
            data
            url
          }
          guid {
            data
            permalink
          }
          enclosure {
            url
            length
            mime
          }
          content
          description
          author
        }
      }
    },
  }
|}
];

module RssFeedQuery = ReasonApolloHooks.Query.Make(RssFeedQueryConfig);

module RssFeed = {
  [@react.component]
  let make = (~url, ~setAudioUrl, ~audioUrl) => {
    open React;
    let variables = RssFeedQueryConfig.make(~url, ())##variables;

    /* Both variant and records available */
    let (_simple, full) =
      RssFeedQuery.use(
        ~fetchPolicy=NetworkOnly,
        ~errorPolicy=All,
        ~variables,
        (),
      );

    switch (full) {
    | {loading: true} => <p> {string("Loading...")} </p>
    | {data, error, refetch} =>
      let jsonify = data =>
        <pre> {string(prettyStringify(data, Js.Nullable.null, 2))} </pre>;
      let dataEl =
        data->Belt.Option.mapWithDefault(string("No data"), jsonify);
      let errorEl = error->Belt.Option.mapWithDefault(null, jsonify);
      let podcastList =
        Belt.Option.(
          data
          ->map(data => data##rss)
          ->map(rss =>
              rss##rss2Feed##items
              ->Array.map(
                  item =>
                    <PodcastCard key=item##title item setAudioUrl audioUrl />,
                  _,
                )
              ->array
            )
          ->getWithDefault(<p> {string("No podcast items")} </p>)
        );

      <div>
        podcastList
        dataEl
        errorEl
        <Reant.Button
          onClick=(
            _event =>
              switch (
                OneGraphAuth.findMissingAuthServices(Client.auth, error)[0]
              ) {
              | serviceName =>
                serviceName
                ->OneGraphAuth.login(Client.auth, _)
                ->Js.Promise.then_(
                    () => OneGraphAuth.isLoggedIn(Client.auth, serviceName),
                    _,
                  )
                ->Js.Promise.then_(
                    loginSuccess =>
                      switch (loginSuccess) {
                      | false =>
                        Js.log2(
                          "The user did not grant auth to ",
                          serviceName,
                        )
                        ->Js.Promise.resolve
                      | true =>
                        Js.log2("Successfully logged into ", serviceName);
                        refetch()->ignore->Js.Promise.resolve;
                      },
                    _,
                  )
                ->ignore
              | exception (Invalid_argument(_)) => refetch()->ignore
              }
          )>
          {string("Rerun RssFeedQuery")}
        </Reant.Button>
      </div>;
    };
  };
};

module ExampleMutationConfig = [%graphql
  {|
  mutation Example($name: String!) {
    __typename
    testMutate(query: $name)
  }
|}
];

module ExampleMutation =
  ReasonApolloHooks.Mutation.Make(ExampleMutationConfig);

module Example = {
  [@react.component]
  let make = (~name) => {
    open React;
    let variables = ExampleMutationConfig.make(~name, ())##variables;

    /* Both variant and records available */
    let (mutation, _simple, full) =
      ExampleMutation.use(
        /* ~fetchPolicy=ReasonApolloHooks.NetworkOnly, */
        /* ~errorPolicy=ReasonApolloHooks.All, */
        ~variables,
        (),
      );

    switch (full) {
    | {loading: true} => <p> {string("Loading...")} </p>
    | {data, error} =>
      let jsonify = data =>
        <pre> {string(prettyStringify(data, Js.Nullable.null, 2))} </pre>;
      let dataEl =
        data->Belt.Option.mapWithDefault(string("No data"), jsonify);
      let errorEl = error->Belt.Option.mapWithDefault(null, jsonify);

      <div>
        dataEl
        errorEl
        <Reant.Button
          _type="default"
          onClick=(
            _event =>
              /** Automatic progressive authentication!
              /   We automatically find which service needs to be authenticated
              /   based on the errors from the last call, then ask the user
              /   to log in if necessary before trying again. */
              (
                switch (
                  OneGraphAuth.findMissingAuthServices(Client.auth, error)[0]
                ) {
                | serviceName =>
                  serviceName
                  ->OneGraphAuth.login(Client.auth, _)
                  ->Js.Promise.then_(
                      () => OneGraphAuth.isLoggedIn(Client.auth, serviceName),
                      _,
                    )
                  ->Js.Promise.then_(
                      loginSuccess =>
                        switch (loginSuccess) {
                        | false =>
                          Js.log2(
                            "The user did not grant auth to ",
                            serviceName,
                          )
                          ->Js.Promise.resolve
                        | true =>
                          Js.log2("Successfully logged into ", serviceName);
                          mutation()->ignore->Js.Promise.resolve;
                        },
                      _,
                    )
                  ->ignore
                | exception (Invalid_argument(_)) => mutation()->ignore
                }
              )
          )>
          {string("Rerun ExampleMutation")}
        </Reant.Button>
      </div>;
    };
  };
};

[@react.component]
let make = () => {
  let (audioUrl, setAudioUrl) = React.useState(() => "");

  <ReasonApolloHooks.ApolloProvider client=Client.client>
    <div>
      <RssFeed
        url="https://www.heavybit.com/category/library/podcasts/jamstack-radio/feed"
        setAudioUrl
        audioUrl
      />
      <div
        style={
          ReactDOMRe.Style.make(
            ~position="fixed",
            ~bottom="20px",
            ~right="20px",
            (),
          )
        }>
        <audio src=audioUrl autoPlay=true controls=true />
      </div>
    </div>
  </ReasonApolloHooks.ApolloProvider>;
};
