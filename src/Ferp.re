/* See https://bucklescript.github.io/docs/en/bind-to-global-values */

[@bs.send]
external app: (~init: 'a, ~update: 'b, ~subscribe: 'c, unit, unit) => unit =
  "";

module None = {
  type t;
};

module Batch = {
  type t;
};

module Effects = {
  type noneRes('a) = {type_: 'a};
  type batchRes('a, 'b) = {
    type_: 'a,
    effects: array('b),
  };
  type thunkRes('a, 'b) = {
    type_: 'a,
    thunk: 'b,
  };
  /* type deferRes = {
       type_: 'a,
       promise: JS.Promise
     }; */

  type t('a, 'b) = {
    none: unit => noneRes('a),
    batch: 'b => batchRes('a, 'b),
    /* defer: (Js.Promise) => deferRes('a), */
    thunk: 'b => thunkRes('a, 'b),
    /* delay: (message: string, ~milliseconds: int, unit) => unit, */
    /* raf: (message: string, ~lastTimestamp: int, unit) => 'b */
    /* defer: (Js.Promise) => 'b, */
  };
};

[@bs.val] external effects: Effects.t('a, 'b) = "";

module Every = {
  type t;
};

module Subscriptions = {
  type t = {every: Every.t};
};

[@bs.val] external subscriptions: Subscriptions.t = "";

module Util = {
  type t('a, 'b) = {
    combineReducers: 'a => 'b,
    pure: 'a => 'b,
  };
};

[@bs.val] external util: Util.t('a, 'b) = "";