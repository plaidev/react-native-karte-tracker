package com.example;

import com.google.firebase.messaging.FirebaseMessagingService;
import com.google.firebase.messaging.RemoteMessage;

import io.karte.android.tracker.firebase.MessageHandler;

public class MyFirebaseMessagingService extends FirebaseMessagingService {

  @Override
  public void onMessageReceived(RemoteMessage remoteMessage) {
    boolean isHandled = MessageHandler.handleMessage(this, remoteMessage);
    if (!isHandled) {
      // KARTE以外から送信されたプッシュ通知の場合に行う処理を記述
    }
  }
}
