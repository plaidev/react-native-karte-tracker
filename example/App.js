/**
 * Sample React Native App
 * https://github.com/facebook/react-native
 *
 * @format
 * @flow
 */

import React, {Component} from 'react';
import {Platform, StyleSheet, Text, View, ScrollView, TextInput, Button, SafeAreaView, Linking, Alert} from 'react-native';
import {KarteTracker, KarteTrackerJsUtil, KarteInAppMessagingManager} from 'react-native-karte-tracker';

type Props = {};
export default class App extends Component<Props> {
  constructor(props) {
    super(props)
    this.state = {
      view: '',
      user_id: '',
      custom: ''
    }
  }
  render() {
    return (
      <SafeAreaView style={styles.container}>
        <ScrollView>
          <View style={styles.subContainer}>
            <Text style={styles.header}>View event</Text>
            <TextInput onChangeText={(view) => this.setState({view})} placeholder="View event name" value={this.state.view} />
            <Button onPress={() => this._onPressSendViewEventButton()} title="Send" />
          </View>
          <View style={styles.subContainer}>
            <Text style={styles.header}>Identify event</Text>
            <TextInput onChangeText={(user_id) => this.setState({user_id})} placeholder="User ID" value={this.state.user_id} />
            <Button onPress={() => this._onPressSendIdentifyEventButton()} title="Send" />
          </View>
          <View style={styles.subContainer}>
            <Text style={styles.header}>Custom event</Text>
            <TextInput onChangeText={(custom) => this.setState({custom})} placeholder="Custom event name" value={this.state.custom} />
            <Button onPress={() => this._onPressSendCustomEventButton()} title="Send" />
          </View>
          <View style={styles.subContainer}>
            <Text style={styles.header}>In-app messaging</Text>
            <Button onPress={() => this._onPressIsPresentingButton()} title="Is presenting" />
            <Button onPress={() => this._onPressDismissButton()} title="Dismiss" />
            <Button onPress={() => this._onPressSuppressButton()} title="Suppress" />
            <Button onPress={() => this._onPressUnsuppressButton()} title="Unsuppress" />
          </View>
          <View style={styles.subContainer}>
            <Text style={styles.header}>Opt-in / out</Text>
            <Button onPress={() => this._onPressOptInButton()} title="Opt-in" />
            <Button onPress={() => this._onPressOptOutButton()} title="Opt-out" />
          </View>
          <View style={styles.subContainer}>
            <Text style={styles.header}>Renew visitor id</Text>
            <Button onPress={() => this._onPressRenewVisitorIdButton()} title="Renew" />
          </View>
        </ScrollView>
      </SafeAreaView>
    )
  }

  componentDidMount() {
    Linking.addEventListener('url', this._handleOpenURL)
    Linking.getInitialURL().then((url) => {
      if (url) {
        console.log(`Linking.getInitialURL is ${url}`)
        this._handleOpenURL({url})
      }
    }).catch(err => console.error('An error occurred', err))
  }

  componentWillUnmount() {
    Linking.removeEventListener('url', this._handleOpenURL)
  }

  _handleOpenURL(event) {
    Alert.alert('Deep link', event.url, [{
      text: 'OK',
      onPress: () => console.log('OK!')
    }]);
  }

  _onPressSendViewEventButton() {
    if (this.state.view.trim().length > 0) {
      KarteTracker.view(this.state.view);
    }
  }

  _onPressSendIdentifyEventButton() {
    if (this.state.user_id.trim().length > 0) {
      KarteTracker.identify({
        user_id: this.state.user_id
      });
    }
  }

  _onPressSendCustomEventButton() {
    if (this.state.custom.trim().length > 0) {
      KarteTracker.track(this.state.custom);
    }
  }

  _onPressIsPresentingButton() {
    console.dir(KarteInAppMessagingManager, {depth: 10})
    KarteInAppMessagingManager.isPresenting((res) => {
      Alert.alert('Is presenting', '' + res, [{
        text: 'OK',
        onPress: () => {}
      }])
    })
  }

  _onPressDismissButton() {
    KarteInAppMessagingManager.dismiss()
  }
  _onPressSuppressButton() {
    KarteInAppMessagingManager.suppress()
  }
  _onPressUnsuppressButton() {
    KarteInAppMessagingManager.unsuppress()
  }
  _onPressOptInButton() {
    KarteTracker.optIn()
  }
  _onPressOptOutButton() {
    KarteTracker.optOut()
  }
  _onPressRenewVisitorIdButton() {
    KarteTracker.renewVisitorId()
  }
}
const styles = StyleSheet.create({
  container: {
    flex: 1,
    // justifyContent: 'center',
    // alignItems: 'center',
    backgroundColor: '#F5FCFF',
    // marginLeft: 16,
    // marginRight: 16
  },
  subContainer: {
    padding: 16
  },
  header: {
    fontSize: 14,
    fontWeight: 'bold',
    marginBottom: 8,
    color: '#333333'
  },
  welcome: {
    fontSize: 20,
    textAlign: 'center',
    margin: 10,
  },
  instructions: {
    textAlign: 'center',
    color: '#333333',
    marginBottom: 5,
  },
})
