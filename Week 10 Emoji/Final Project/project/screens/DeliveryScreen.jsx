import { View, Text, SafeAreaView, TouchableOpacity, Image } from 'react-native'
import React from 'react'
import { useNavigation } from '@react-navigation/native'
import { useSelector } from 'react-redux';
import { selectRestaurant } from '../features/restaurant';
import SafeViewAndroid from '../components/SafeViewAndroid';
import { XMarkIcon } from 'react-native-heroicons/solid';
import * as Progress from 'react-native-progress';
import MapView, { Marker } from 'react-native-maps';
const DeliveryScreen = () => {
    const navigation = useNavigation();
    const restaurant = useSelector(selectRestaurant);

    return (
        <View className="bg-[#00CCBB] flex-1">
            <SafeAreaView style={ SafeViewAndroid.AndroidSafeArea } className="z-50" >
                <View className="flex-row justify-between items-center p-5">

                    <TouchableOpacity onPress={ () => navigation.navigate('Home') }>
                        <XMarkIcon color="white" size={ 30 } />
                    </TouchableOpacity>
                    <Text className="font-light text-white text-lg">Order Help</Text>
                </View>
                <View className="bg-white mx-5 my-2 rounded-md p-6 z-50 shadow-md">
                    <View className="flex-row justify-between">

                        <View>
                            <Text className="text-lg text-gray-400">Estimated Arrival</Text>
                            <Text className="text-4xl font-bold">30-45 Minutes</Text>
                        </View>
                        <Image
                            source={ {
                                uri:"https://media.istockphoto.com/id/1250495017/vector/courier-rides-a-bicycle-on-a-city.jpg?s=612x612&w=0&k=20&c=PAulV7kSoz91X-p1Hm0v_fTNSxtSLJIiLVSFa8r-mqI="
                            } }
                            className="h-20 w-20"
                        />
                    </View>
                    <Progress.Bar progress={ 0.3 } width={ 200 } indeterminate={ true } />
                    <Text className="mt-3 text-gray-500">
                        Your order at { restaurant.title } is being prepared
                    </Text>
                </View>
            </SafeAreaView>
            <MapView
                region={ {
                    
                    latitude: restaurant.lat,
                    longitude: restaurant.long,
                    latitudeDelta: 0.05,
                    longitudeDelta: 0.05,
                }}
                className="flex-1 -mt-80 z-0"
                mapType='mutedStandard'
                zoomEnabled={ true }
                showsUserLocation={ true }
                zoomControlEnabled={true}
            >

                <Marker
                    key={1}
                    coordinate={ {
                        latitude: restaurant.lat,
                        longitude: restaurant.long,

                    } }
                    title={ restaurant?.title }
                    description={ restaurant?.description }
                    identifier="origin"
                    pinColor='#00CCBB'
                    
                />

            </MapView>
            <SafeAreaView className="bg-white flex-row items-center space-x-5 h-20">
                <Image
                    source={ {
                        uri:"https://media.istockphoto.com/id/1250495017/vector/courier-rides-a-bicycle-on-a-city.jpg?s=612x612&w=0&k=20&c=PAulV7kSoz91X-p1Hm0v_fTNSxtSLJIiLVSFa8r-mqI="
                    } }
                    className="h-10 w-10 bg-gray-300 p-4 rounded-full ml-5"
                />
                <View className="flex-1">
                    <Text className="text-lg">Sunny Dawar</Text>
                    <Text className="text-gray-400">Your Rider</Text>
                </View>
                <Text className="text-[#00CCBB] text-lg mr-5 font-bold">
                    Call
                </Text>
            </SafeAreaView>
        </View>
    )
}

export default DeliveryScreen