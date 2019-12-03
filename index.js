
import { NativeModules } from 'react-native'

const { RNKarteTrackerModule } = NativeModules

function _exec(operation, callback) {
  let result;
  if (typeof callback !== 'function') {
    result = new Promise(resolve => {
      callback = (result) => {
        resolve(result)
      }
    })
  }

  operation(callback)
  return result
}

const KarteTracker = {

  getAppKey: (cb) => {
    return _exec(cb => {
      RNKarteTrackerModule.getAppKey(cb)
    }, cb)
  },

  getVisitorId: (cb) => {
    return _exec(cb => {
      RNKarteTrackerModule.getVisitorId(cb)
    }, cb)
  },

  track: (eventName, values) => {
    RNKarteTrackerModule.track(eventName, values)
  },

  identify: (values) => {
    RNKarteTrackerModule.identify(values)
  },

  view: (viewName, title, values) => {
    RNKarteTrackerModule.view(viewName, title, values)
  },

  registerFCMToken: (fcmToken) => {
    RNKarteTrackerModule.registerFCMToken(fcmToken)
  },

  optIn: () => {
    RNKarteTrackerModule.optIn()
  },

  optOut: () => {
    RNKarteTrackerModule.optOut()
  },

  renewVisitorId: () => {
    RNKarteTrackerModule.renewVisitorId()
  }
};

const KarteTrackerJsUtil = {

  appendUserSyncQueryParameter: (url, cb) => {
    return _exec(cb => {
      RNKarteTrackerModule.appendUserSyncQueryParameter(url, cb)
    }, cb)
  }
}

const KarteInAppMessagingManager = {

  isPresenting: (cb) => {
    return _exec(cb => {
      RNKarteTrackerModule.isPresenting(cb)
    }, cb)
  },

  dismiss: () => {
    RNKarteTrackerModule.dismiss()
  },

  suppress: () => {
    RNKarteTrackerModule.suppress()
  },

  unsuppress: () => {
    RNKarteTrackerModule.unsuppress()
  }
}

const KarteVariables = {

  fetch: (cb) => {
    return _exec(cb => {
      RNKarteTrackerModule.fetch(cb)
    }, cb)
  },

  variable: (key, cb) => {
    return _exec(cb => {
      RNKarteTrackerModule.variable(key, vals => {
        cb(new KarteVariable(vals))
      })
    }, cb)
  },

  track: (variables, eventName, values) => {
    let vals = variables.map((variable) => {
      return {
        "campaign_id": variable.campaignId,
        "shorten_id": variable.shortenId
      }
    })
    RNKarteTrackerModule.trackVariables(vals, eventName, values)
  }
}

class KarteVariable {
  constructor(vals) {
    this.key = vals["key"]
    this.campaignId = vals["campaign_id"]
    this.shortenId = vals["shorten_id"]
    this.isDefined = vals["is_defined"]
  }

  string(defaultValue, cb) {
    return _exec(cb => {
      RNKarteTrackerModule.stringForKey(this.key, defaultValue, cb)
    }, cb)
  }

  integer(defaultValue, cb) {
    return _exec(cb => {
      RNKarteTrackerModule.integerForKey(this.key, defaultValue, cb)
    }, cb)
  }

  double(defaultValue, cb) {
    return _exec(cb => {
      RNKarteTrackerModule.doubleForKey(this.key, defaultValue, cb)
    }, cb)
  }

  bool(defaultValue, cb) {
    return _exec(cb => {
      RNKarteTrackerModule.boolForKey(this.key, defaultValue, cb)
    }, cb)
  }

  array(defaultValue, cb) {
    return _exec(cb => {
      RNKarteTrackerModule.arrayForKey(this.key, defaultValue, cb)
    }, cb)
  }

  object(defaultValue, cb) {
    return _exec(cb => {
      RNKarteTrackerModule.objectForKey(this.key, defaultValue, cb)
    }, cb)
  }
}

export { KarteTracker, KarteTrackerJsUtil, KarteInAppMessagingManager, KarteVariables }
export default KarteTracker
