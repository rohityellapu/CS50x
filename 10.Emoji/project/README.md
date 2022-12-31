# Deliverio
#### Video Demo: [https://youtu.be/gZM1vMrrzIs](https://youtu.be/gZM1vMrrzIs)
#### Description: A Food Delivery mobile application built on [React-Native](https://reactnative.dev/) with help of [Expo Go](https://expo.dev/) compatible on both Android and iOS.
* Used [TailWind CSS](https://www.nativewind.dev/) (NativeWind for React-Native) for aesthetics of screens.
* Data is stored and managed by [sanity](https://www.sanity.io/) which uses GraphQL query Language for querying data and designing schema models.
* The app use [Redux](https://redux.js.org/) state container which stores the state of items in order basket and restaurant state globally.
* The app contains lots of icons taken from react-native-icons which made easy in sizing and coloring components.

### Technologies used
* Expi Go
* React-Native
* TailWind CSS
* Sanity
* GraphQL
* React Stack Navigation
* React Animatable
* React Redux

# Getting Started

## Install dependencies/Libraries
### In CMD run
## `npm install` or `yarn add`

## Start application

## `expo start`

### Add  ` --web` at the end of command if running on web, add ` --android` if running on android or ` --ios` if running on ios.

* To see your results you can use android sumulator and physical android device but for iOS,
* You may need Mac iOS for running in iOS Simulator or you physical iOS mobile device

* Note: If running on web the CSS properties may get errors, Use Nativewind Documentation for proper usage. Quick solution is uncomment lines 1-9 in App.js while running on web and comment it if running on other platforms.

## For Sanity
Go inside sanity folder and install all depencies and run
### `sanity dev` and upon production run `sanity build`

* Note: You must login to sanity and configure your account credentials before running sanity SDK.

### Note:
You may get version variants warnings you can change the versions in package.json file in the dependencies list or you can ignore if it doesn't break the application.

## More
* Add more schemas of Data models in schemas folder inside sanity folder
* Confige CSS as need with both sanity and expo.
* You can add more screens to your app and add it into Stack Navigation in App.js main file.
* Config redux store by adding user data globally.