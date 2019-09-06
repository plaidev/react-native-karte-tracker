# example
`example` は、[react-native-karte-tracker](https://github.com/plaidev/react-native-karte-tracker) の検証を行うためのアプリケーションです。

## 開発環境のセットアップ
### 1. 開発に必要なソースコードを取得する

```bash
$ git clone https://github.com/plaidev/react-native-karte-tracker.git
```

### 2. 依存ライブラリ等を取得する
#### 共通で必要とする依存ライブラリのインストール
```bash
$ cd react-native-karte-tracker/example
$ npm install
```

#### iOSのみで必要とする依存ライブラリのインストール
```bash
$ cd react-native-karte-tracker/example/ios
$ pod install
```

#### Androidのみで必要とする依存ライブラリのインストール
特になし

### 3. 初期設定
#### アプリケーションキーの設定
KARTE SDKによる計測を行うために、アプリケーションキーの設定を行う。
対象のファイルを開き、「YOUR_APP_KEY」部分を実際のキーに置き換える。

```bash
$ cd react-native-karte-tracker/example/ios/Example
$ vi AppDelegate.m
$ cd react-native-karte-tracker/example/android/app/src/main/java/com/example
$ vi MainApplication.java
$ vi MyFirebaseMessagingService.java
```

#### Firebase設定ファイルの配置
*iOS*
`react-native-karte-tracker/example/ios/Example` 直下に `GoogleService-Info.plist` を配置する

*Android*
`react-native-karte-tracker/example/android/app` 直下に `google-services.json` を配置する

### 4. アプリを実行する
#### iOS
```
$ cd react-native-karte-tracker/example
$ react-native run-ios
```

#### Android
```
$ cd react-native-karte-tracker/example
$ react-native run-android
```
