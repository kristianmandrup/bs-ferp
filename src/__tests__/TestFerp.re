open Ferp;
open Jest;
open ExpectJs;

type appState = {name: string};
type subscibe = {every: bool};
let sub = {every: true};
let update = state => state;
let state = "x";

describe("Ferp", () => {
  test("#app", () =>
    expect(() =>
      app(~init=state, ~update, ~subscribe=sub, ())
    )
    |> not
    |> toThrow
  );

  test("#subscriptions", () =>
    expect(() =>
      subscriptions
    ) |> not |> toThrow
  );

  test("#effects", () =>
    expect(() =>
      effects
    ) |> not |> toThrow
  );

  test("#util", () =>
    expect(() =>
      util
    ) |> not |> toThrow
  );
});