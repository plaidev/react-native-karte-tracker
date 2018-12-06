
package io.karte.reactnative;

import com.facebook.react.bridge.Callback;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import com.facebook.react.bridge.ReadableMap;

import org.json.JSONObject;

import io.karte.android.tracker.Tracker;
import io.karte.android.tracker.TrackerJsUtil;

public class RNKarteTrackerModule extends ReactContextBaseJavaModule {

  private final ReactApplicationContext reactContext;

  public RNKarteTrackerModule(ReactApplicationContext reactContext) {
    super(reactContext);
    this.reactContext = reactContext;
  }

  @Override
  public String getName() {
    return "RNKarteTrackerModule";
  }

  //
  // Tracker

  @ReactMethod
  public void getAppKey(Callback callback) {
    String appKey = getDefaultTracker().getAppKey();
    callback.invoke(null, appKey);
  }

  @ReactMethod
  public void getVisitorId(Callback callback) {
    String visitorId = getDefaultTracker().getVisitorId();
    callback.invoke(null, visitorId);
  }

  @ReactMethod
  public void track(String eventName, ReadableMap map) {
    getDefaultTracker().track(eventName, toJSONObject(map));
  }

  @ReactMethod
  public void identify(ReadableMap map) {
    getDefaultTracker().identify(toJSONObject(map));
  }

  @ReactMethod
  public void view(String viewName, String title, ReadableMap map) {
    getDefaultTracker().view(viewName, title, toJSONObject(map));
  }

  @ReactMethod
  public void registerFCMToken(String fcmToken) {
    getDefaultTracker().trackFcmToken(fcmToken);
  }

  //
  // TrackerJsUtil

  @ReactMethod
  public void appendUserSyncQueryParameter(String url, Callback callback) {
    String appKey = getDefaultTracker().getAppKey();
    String newURL = TrackerJsUtil.appendUserSyncQueryParameter(getReactApplicationContext(), appKey, url);
    callback.invoke(null, newURL);
  }

  private Tracker getDefaultTracker() {
    return Tracker.getInstance(getReactApplicationContext());
  }

  private JSONObject toJSONObject(ReadableMap map) {
    if (map == null) {
      return null;
    }
    return new JSONObject(map.toHashMap());
  }
}