/* patch */
[@bs.send] external app: (~init: 'a, ~update: 'b, ~subscribe: 'c, unit) => (unit) => unit = ""

module None = {
  type t;
};

module Batch = {
  type t;
};


module Effects = {
  type noneRes('a) = {
    type_: 'a
  };
  type batchRes('a, 'b) = {
    type_: 'a,
    effects: array('b)
  };
  /* type deferRes('a) = {
    type_: 'a,
    promise: Js.Promise
  }; */
  type thunkRes('a, 'b) = {
    type_: 'a,
    thunk: 'b
  }
   
  type t('a, 'b) = {
    none: (unit) => noneRes('a),
    batch: ('b) => batchRes('a, 'b),
    /* defer: (Js.Promise) => deferRes('a), */
    /* thunk: ('b) => thunkRes('a, 'b) */
    /* delay: Delat.t, */
    /* raf: Raf.t, */
  };
};

external effects: Effects.t;

module Every = {
  type t;
};

module Subscriptions = {
  type t = {
    every: Every.t,
  };
};
external subscriptions: Subscriptions.t;

module Util = {
  type t = {
    combineReducers: unit => unit,
    pure: unit => unit,
  };
};
external util: Util.t;