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
* Add more schemas of Data models in schemas folder inside sanity folder and import it to index file to include it into schemaTypes
```javascript
import featured from './featured'
import category from './category'
import restaurant from './restaurant'
import dish from './dish'

export const schemaTypes = [restaurant, dish, category, featured]
```
* Confige CSS as need with both sanity and expo add the folders/files wherever you use tailwind css classnames in tailwind.congig.js file

```javascript
/** @type {import('tailwindcss').Config} */
module.exports = {

  content: [
    "./App.js",
    "./index.html",
    "./src/**/*.{vue,js,ts,jsx,tsx}",
    "./screens/**/*.{js,jsx,ts,tsx}",
    "./components/**/*.{js,jsx,ts,tsx}"
  ],
  theme: {
    extend: {},
  },
  plugins: [],
}

```
* You can add more screens to your app and add it into Stack Navigation in App.js main file.
```javascript

import { NavigationContainer } from '@react-navigation/native';
import { createNativeStackNavigator } from '@react-navigation/native-stack';
import RestaurantScreen from './screens/RestaurantScreen';
import HomeScreen from './screens/HomeScreen';
import { Provider } from 'react-redux';
import store from './store';
import BasketScreen from './screens/BasketScreen';
import PreparingScreen from './screens/PreparingScreen';
import DeliveryScreen from './screens/DeliveryScreen';
const Stack = createNativeStackNavigator();

export default function App() {
  return (

    <NavigationContainer>
      <Provider store={store}>
      <Stack.Navigator>
        <Stack.Screen name="Home" component={ HomeScreen } />
        <Stack.Screen name="Restaurant" component={ RestaurantScreen } />
          <Stack.Screen name="Basket" component={ BasketScreen }
            options={{presentation:'modal', headerShown:false}}
          />
          <Stack.Screen name="Preparing" component={ PreparingScreen } options={ { presentation: 'fullScreenModal', headerShown: false } } />
          <Stack.Screen name="Delivery" component={ DeliveryScreen } options={ { presentation: 'fullScreenModal', headerShown: false } } />
      </Stack.Navigator>
      </Provider>
    </NavigationContainer>

  );
}
```

* Config redux store as per your need(for example add another userData file in features and config it in store.js file
```javascript
import { configureStore } from '@reduxjs/toolkit'
import basketReducer from './features/basket'
import restaurantReducer from './features/restaurant'
export default configureStore({
    reducer: {
        basket: basketReducer,
        restaurant: restaurantReducer
    }
})
```


# Author: Rohit Yellapu
## Reach me
* [Git](https://github.com/rohityellapu)
* [Linkedin](https://www.linkedin.com/in/rohit-yellapu)
* [Twitter](https://twitter.com/rohit_yellapu)