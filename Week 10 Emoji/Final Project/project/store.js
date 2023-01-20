import { configureStore } from '@reduxjs/toolkit'
import basketReducer from './features/basket'
import restaurantReducer from './features/restaurant'
export default configureStore({
    reducer: {
        basket: basketReducer,
        restaurant: restaurantReducer
    }
})