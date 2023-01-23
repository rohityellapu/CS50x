import { View, Text, TouchableOpacity, ScrollView } from 'react-native'
import React, { useState, useMemo } from 'react'
import { useNavigation } from '@react-navigation/native'
import { useDispatch, useSelector } from 'react-redux';
import { selectRestaurant } from '../features/restaurant';
import { removeFromBasket, selectBasketItems, selectBasketTotal } from '../features/basket';
import { SafeAreaView } from 'react-native';
import SafeViewAndroid from "../components/SafeViewAndroid";
import { XCircleIcon } from 'react-native-heroicons/solid';
import { Image } from 'react-native';
import Currency from 'react-currency-formatter';


const BasketScreen = () => {
    const navigation = useNavigation();
    const restaurant = useSelector(selectRestaurant);
    const items = useSelector(selectBasketItems)
    const basketTotal =  useSelector(selectBasketTotal)
    const dispatch = useDispatch();
    const [itemsInBasket, setitemsInBasket] = useState([])

    useMemo(() => {
        const groupedItems = items.reduce((res, item) => {
            (res[item.id] = res[item.id] || []).push(item);
            return res;
        }, {})
        setitemsInBasket(groupedItems)
    }, [items])

    return (
        <SafeAreaView style={ SafeViewAndroid.AndroidSafeArea } className="flex-1 bg-white">
            <View className="flex-1 bg-gray-100">
                <View className="p-5 border-b border-[#00CCBB] bg-white shadow-xs">
                    <View>
                        <Text className="text-lg font-bold text-center">Basket</Text>
                        <Text className="text-center text-gray-400">{ restaurant.title }</Text>
                    </View>
                    <TouchableOpacity onPress={ navigation.goBack } className="rounded-full bg-gray-100 absolute top-3 right-5">
                        <XCircleIcon color="#00CCBB" height={ 50 } width={ 50 } />
                    </TouchableOpacity>
                </View>
                <View className="flex-row items-center space-x-2 px-4 py-3 bg-white my-5">
                    <Image
                        source={ {
                            uri: "https://media.istockphoto.com/id/1250495017/vector/courier-rides-a-bicycle-on-a-city.jpg?s=612x612&w=0&k=20&c=PAulV7kSoz91X-p1Hm0v_fTNSxtSLJIiLVSFa8r-mqI="
                        } }
                        className="h-7 w-7 bg-gray-300 p-4 rounded-full"
                    />
                    <Text className="flex-1">Delivery in 30-45 min</Text>
                    <TouchableOpacity>
                        <Text className="text-[#00CCBB]">Change</Text>
                    </TouchableOpacity>
                </View>
                <ScrollView className="divide-y divide-gray-200">
                    { Object.entries(itemsInBasket).map(([key, items]) => (
                        <View key={ key } className="flex-row items-center space-x-3 bg-white py-2 px-5">
                            <Text className="text-[#00CCBB]">{ items.length } x</Text>
                            <Image
                                source={ {
                                    uri: items[0]?.image
                                } }
                                className="h-12 w-12 rounded-full"
                            />
                            <Text className="flex-1">{ items[0]?.name }</Text>
                            <Text className="text-gray-600">
                                <Currency quantity={ items[0].price } currency="INR" />
                            </Text>
                            <TouchableOpacity>
                                <Text
                                    className="text-[#00CCBB] text-xs"
                                    onPress={() => dispatch(removeFromBasket({id:key}))}
                                >Remove</Text>
                            </TouchableOpacity>
                        </View>
                    )) }
                </ScrollView>
                <View className="p-5 bg-white mt-5 space-y-4">
                    <View className="flex-row justify-between">
                        <Text className="text-gray-400">Subtotal</Text>
                        <Text className="text-gray-400">
                            <Currency quantity={ basketTotal } currency="INR" />
                        </Text>
                    </View>
                    <View className="flex-row justify-between">
                        <Text className="text-gray-400">Delivery Fee</Text>
                        <Text className="text-gray-400">
                            <Currency quantity={ 45 } currency="INR" />
                        </Text>
                    </View>
                    <View className="flex-row justify-between">
                        <Text className="">Order Total</Text>
                        <Text className="font-extrabold">
                            <Currency quantity={ 45 + basketTotal } currency="INR" />
                        </Text>
                    </View>
                    <TouchableOpacity onPress={() => navigation.navigate('Preparing')} className="rounded-lg bg-[#00CCBB] p-4">
                        <Text className="text-center text-white text-lg font-bold">Place Order</Text>
                    </TouchableOpacity>
                </View>
            </View>
        </SafeAreaView>
    )
}

export default BasketScreen