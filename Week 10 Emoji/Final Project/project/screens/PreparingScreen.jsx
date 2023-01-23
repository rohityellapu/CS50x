import { View, Text, SafeAreaView } from 'react-native'
import React, { useEffect } from 'react'
import * as Animatable from 'react-native-animatable'
import * as Progress from 'react-native-progress';
import { useNavigation } from '@react-navigation/native';
const PreparingScreen = () => {
    const navigation = useNavigation();
    useEffect(() => {
        setTimeout(() => {
            navigation.navigate('Delivery')
        }, 4000)
    },[])

    return (
        <SafeAreaView  className="bg-[#00CCBB] flex-1 justify-center items-center">
            <Animatable.Image
                source={ require('../assets/delivery-boy.gif') }
                animation="slideInUp"
                className="h-96 w-96"
                iterationCount={1}
            />
            <Animatable.Text
                animation="slideInUp"
                className="text-lg my-10 text-white font-bold text-center"
                iterationCount={ 1 }
            >
                Waiting for Restaurant to accept your offer
            </Animatable.Text>
            <Progress.Circle size={ 50 } indeterminate={ true } fill="#00000000" />
        </SafeAreaView>
    )
}

export default PreparingScreen