package com.example;

import io.karte.android.tracker.Tracker;
import io.karte.android.tracker.firebase.KarteFirebaseInstanceIdService;

public class MyKarteFirebaseInstanceIdService extends KarteFirebaseInstanceIdService {

  @Override
  protected Tracker getTracker() {
    return Tracker.getInstance(this, "YOUR_APP_KEY");
  }
}
