
package io.karte.reactnative;

import com.facebook.react.bridge.Arguments;
import com.facebook.react.bridge.Callback;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import com.facebook.react.bridge.ReadableArray;
import com.facebook.react.bridge.ReadableMap;
import com.facebook.react.bridge.WritableMap;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.util.ArrayList;
import java.util.List;

import io.karte.android.tracker.Tracker;
import io.karte.android.tracker.TrackerJsUtil;
import io.karte.android.tracker.Variable;
import io.karte.android.tracker.Variables;
import io.karte.android.tracker.inappmessaging.InAppMessagingManager;

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
    callback.invoke(appKey);
  }

  @ReactMethod
  public void getVisitorId(Callback callback) {
    String visitorId = getDefaultTracker().getVisitorId();
    callback.invoke(visitorId);
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

  @ReactMethod
  public void optIn() {
    getDefaultTracker().optIn();
  }

  @ReactMethod
  public void optOut() {
    getDefaultTracker().optOut();
  }

  @ReactMethod
  public void renewVisitorId() {
    getDefaultTracker().renewVisitorId();
  }

  //
  // TrackerJsUtil

  @ReactMethod
  public void appendUserSyncQueryParameter(String url, Callback callback) {
    String appKey = getDefaultTracker().getAppKey();
    String newURL = TrackerJsUtil.appendUserSyncQueryParameter(getReactApplicationContext(), appKey, url);
    callback.invoke(newURL);
  }

  //
  // InAppMessagingManager

  @ReactMethod
  public void isPresenting(Callback callback) {
    InAppMessagingManager manager = getDefaultTracker().getInAppMessagingManager();
    callback.invoke(manager.isPresenting());
  }

  @ReactMethod
  public void dismiss() {
    getDefaultTracker().getInAppMessagingManager().dismiss();
  }

  @ReactMethod
  public void suppress() {
    getDefaultTracker().getInAppMessagingManager().suppress();
  }

  @ReactMethod
  public void unsuppress() {
    getDefaultTracker().getInAppMessagingManager().unsuppress();
  }


  //
  // Variables

  @ReactMethod
  public void fetch(final Callback callback) {
    String appKey = getDefaultTracker().getAppKey();
    Variables.getInstance(getReactApplicationContext(), appKey).fetch(new Variables.CompletionHandler() {
      @Override
      public void onCompleted(boolean b) {
        callback.invoke(b);
      }
    });
  }

  @ReactMethod
  public void variable(String key, Callback callback) {
    String appKey = getDefaultTracker().getAppKey();
    Variables variables = Variables.getInstance(getReactApplicationContext(), appKey);

    Variable variable = variables.getVariable(key);

    WritableMap map = Arguments.createMap();
    map.putString("key", key);
    map.putString("campaign_id", variable.getCampaignId());
    map.putString("shorten_id", variable.getShortenId());
    map.putString("string", variable.getString(null));

    callback.invoke(map);
  }

  @ReactMethod
  public void trackVariables(ReadableArray vals, String eventName, ReadableMap values) {
    List<Variable> variables = new ArrayList<>();

    for (int i = 0; i < vals.size(); i++) {
      ReadableMap map = vals.getMap(i);
      String campaignId = map.getString("campaign_id");
      String shortenId = map.getString("shorten_id");
      variables.add(new Variable(null, campaignId, shortenId));
    }

    String appKey = getDefaultTracker().getAppKey();
    Variables.getInstance(getReactApplicationContext(), appKey).track(variables, eventName, toJSONObject(values));
  }

  //
  // Variable

  @ReactMethod
  public void stringForKey(String key, String defaultValue, Callback callback) {
    String appKey = getDefaultTracker().getAppKey();
    Variable variable = Variables.getInstance(getReactApplicationContext(), appKey).getVariable(key);

    callback.invoke(variable.getString(defaultValue));
  }

  @ReactMethod
  public void integerForKey(String key, Integer defaultValue, Callback callback) {
    String appKey = getDefaultTracker().getAppKey();
    Variable variable = Variables.getInstance(getReactApplicationContext(), appKey).getVariable(key);

    callback.invoke((int)variable.getLong(defaultValue));
  }

  @ReactMethod
  public void doubleForKey(String key, Double defaultValue, Callback callback) {
    String appKey = getDefaultTracker().getAppKey();
    Variable variable = Variables.getInstance(getReactApplicationContext(), appKey).getVariable(key);

    callback.invoke(variable.getDouble(defaultValue));
  }

  @ReactMethod
  public void boolForKey(String key, Boolean defaultValue, Callback callback) {
    String appKey = getDefaultTracker().getAppKey();
    Variable variable = Variables.getInstance(getReactApplicationContext(), appKey).getVariable(key);

    callback.invoke(variable.getBoolean(defaultValue));
  }

  @ReactMethod
  public void arrayForKey(String key, ReadableArray defaultValue, Callback callback) {
    String appKey = getDefaultTracker().getAppKey();
    Variable variable = Variables.getInstance(getReactApplicationContext(), appKey).getVariable(key);

    JSONArray jsonArray = variable.getJSONArray(toJSONArray(defaultValue));
    if (jsonArray == null) {
      callback.invoke();
    } else {
      try {
        callback.invoke(Converter.convertJsonToArray(jsonArray));
      } catch (JSONException e) {
        callback.invoke();
      }
    }
  }

  @ReactMethod
  public void objectForKey(String key, ReadableMap defaultValue, Callback callback) {
    String appKey = getDefaultTracker().getAppKey();
    Variable variable = Variables.getInstance(getReactApplicationContext(), appKey).getVariable(key);

    JSONObject jsonObject = variable.getJSONObject(toJSONObject(defaultValue));
    if (jsonObject == null) {
      callback.invoke();
    } else {
      try {
        callback.invoke(Converter.convertJsonToMap(jsonObject));
      } catch (JSONException e) {
        callback.invoke();
      }
    }
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

  private JSONArray toJSONArray(ReadableArray array) {
    if (array == null) {
      return null;
    }
    return new JSONArray(array.toArrayList());
  }
}