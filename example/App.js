/**
 * Sample React Native App
 * https://github.com/facebook/react-native
 *
 * @format
 * @flow
 */

import React, {Component} from 'react';
import {Platform, StyleSheet, Text, TextInput, Button, View, SafeAreaView, Linking, Alert} from 'react-native';

import KarteTracker from 'react-native-karte-tracker';

const instructions = Platform.select({
  ios: 'Press Cmd+R to reload,\n' + 'Cmd+D or shake for dev menu',
  android:
    'Double tap R on your keyboard to reload,\n' +
    'Shake or press menu button for dev menu',
});

export default class App extends Component {
  constructor(props) {
    super(props);
    this.state = {
      view: '',
      user_id: '',
      custom: ''
    };
  }

  componentDidMount() {
    Linking.addEventListener('url', this._handleOpenURL);
    Linking.getInitialURL().then((url) => {
      if (url) {
        console.log(`Linking.getInitialURL is ${url}`);
        this._handleOpenURL({url});
      }
    }).catch(err => console.error('An error occurred', err));
  }

  componentWillUnmount() {
    Linking.removeEventListener('url', this._handleOpenURL);
  }

  render() {
    return (
      <SafeAreaView style={styles.container}>
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
      </SafeAreaView>
    );
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
});
