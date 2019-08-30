
import { NativeModules } from 'react-native'

const { RNKarteTrackerModule } = NativeModules

const KarteTracker = {

  getAppKey: (callback) => {
    RNKarteTrackerModule.getAppKey(callback)
  },

  getVisitorId: (callback) => {
    RNKarteTrackerModule.getVisitorId(callback)
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

  appendUserSyncQueryParameter: (url, callback) => {
    RNKarteTrackerModule.appendUserSyncQueryParameter(url, callback)
  }
}

const KarteInAppMessagingManager = {

  isPresenting: (callback) => {
    RNKarteTrackerModule.isPresenting(callback)
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

export default { KarteTracker, KarteTrackerJsUtil, KarteInAppMessagingManager }
