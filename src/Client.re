/* Change this to be your GraphQL endpoint */
let graphQLUri = "http://localhost:8080/v1/graphql";

/* Create an InMemoryCache */
let inMemoryCache = ApolloInMemoryCache.createInMemoryCache();

/* Create an HTTP Link */
let httpLink = ApolloLinks.createHttpLink(~uri=graphQLUri, ());

/* WebSocket client */
let webSocketLink =
  ApolloLinks.webSocketLink(
    ~uri="ws://localhost:8080/v1/graphql",
    ~reconnect=true,
    (),
  );

/* based on test, execute left or right */
let webSocketHttpLink =
  ApolloLinks.split(
    operation => {
      let operationDefition =
        ApolloUtilities.getMainDefinition(operation##query);
      operationDefition##kind == "OperationDefinition"
      &&
      operationDefition##operation == "subscription";
    },
    webSocketLink,
    httpLink,
  );

let client =
  ReasonApollo.createApolloClient(
    ~link=webSocketHttpLink,
    ~cache=inMemoryCache,
    (),
  );
