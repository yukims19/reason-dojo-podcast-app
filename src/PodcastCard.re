open React;

[@react.component]
let make = (~item, ~setAudioUrl, ~audioUrl) => {
  let itemAudioUrl =
    item##enclosure
    ->Belt.Option.mapWithDefault("", enclosure => enclosure##url);

  let isPlaying = itemAudioUrl == audioUrl;

  let author = item##author->Belt.Option.mapWithDefault(null, string);
  let description = item##description->Belt.Option.getWithDefault("");

  <Reant.Card>
    <h2> item##title->string </h2>
    <i> author </i>
    <div dangerouslySetInnerHTML={"__html": description} />
    <div
      style={ReactDOMRe.Style.make(~display="flex", ~alignItems="center", ())}>
      {
        isPlaying ?
          null :
          <Reant.Button
            _type="primary"
            shape="circle"
            icon="caret-right"
            onClick={_event => setAudioUrl(_currentAudioUrl => itemAudioUrl)}
          />
      }
      <Reant.Button
        _type="danger"
        shape="circle"
        icon="heart"
        onClick={_event => Js.log("Save to like ")}
      />
    </div>
  </Reant.Card>;
};
