# React Native Tracker
`React Native Tracker` は、[react-native-karte-tracker](https://github.com/plaidev/react-native-karte-tracker) の開発および検証を行うためのアプリケーションです。

## 開発環境のセットアップ
### 1. 開発に必要なソースコードを取得する

```bash
$ git clone https://github.com/plaidev/react-native-karte-tracker.git
$ git clone https://github.com/plaidev/react-native-tracker.git
```

### 2. 依存ライブラリ等を取得する
#### 共通で必要とする依存ライブラリのインストール
```bash
$ cd react-native-tracker
$ npm install
```

#### iOSのみで必要とする依存ライブラリのインストール
```bash
$ cd ios
$ pod install
```

#### Androidのみで必要とする依存ライブラリのインストール
特になし

### 3. ローカルで開発するための設定を行う
ステップ2で共通で必要とするライブラリをインストールしたが、そのままではnpmで公開している `react-native-karte-tracker` がインストールされてしまう。<br>
開発時はローカルのファイルを参照したいので、ステップ1でチェックアウトした `react-native-karte-tracker` とリンクする処理を行う。

#### react-native-karte-trackerのルートディレクトリで作業
```bash
$ npm link
```

#### react-native-trackerのルートディレクトリで作業
```bash
$ npm link react-native-karte-tracker
```

### 4. ビルドを行う
#### iOS
- `react-native-tracker/ios/Example.xcworkspace` を開く
- `⌘ + B` でビルドを行う （エラーが発生しなければOK）

#### Android
- Android Studioを起動
- `react-native-tracker/android` を開く
- `[Build]` - `[Rebuild Project]` をクリックしてビルドを行う （エラーが発生しなければOK）

### 5. 開発を始める
#### RN側インターフェース開発
`react-native-karte-tracker/index.js` がインターフェースを定義しているファイル。
現状はこのファイルに全インターフェースが集約されているため、このファイルのみをいじればOK。

#### RN<->Native(iOS)ブリッジ開発 
`react-native-karte-tracker/ios/` 直下の `RNKarteTrackerModule.h/m` にブリッジの実装がある。<br>
開発する場合は `RNKarteTrackerModule.m` を修正する。

Xcodeで開発する場合は、`react-native-tracker/ios/Example.xcworkspace` を開き、`Libraries/RNKarteTracker.xcodeproj` からファイルを編集すると補完が効くので楽。

![RNKarteTrackerModule.m](https://user-images.githubusercontent.com/1884760/63845907-bab9f480-c9c5-11e9-895d-978a48faa32f.jpg)

#### RN<->Native(Android)ブリッジ開発 
`react-native-karte-tracker/android/src/main/java/io/karte/reactnative` 直下にブリッジの実装がある。
開発する場合は以下のファイルを修正する。
- RNKarteTrackerModule.java
- RNKarteTrackerPackage.java (こちらを修正することはあまりないはず）

Android Studioで開発する場合は、`react-native-tracker/android` を開き、`react-native-karte-tracker/java` からファイルを編集すると補完が効くので楽。

![RNKarteTrackerModule.java](https://user-images.githubusercontent.com/1884760/63846723-5009b880-c9c7-11e9-9005-9690030a7609.jpg)

### 6. アプリを実行する
#### iOS
```
$ npx react-native run-ios
```

#### Android
```
$ npx react-native run-android
```
