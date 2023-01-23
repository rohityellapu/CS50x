
import { View, Text, SafeAreaView, Image, TextInput, ScrollView, StyleSheet, Platform } from 'react-native'
import React, { useLayoutEffect, useState, useEffect } from 'react'
import { useNavigation } from '@react-navigation/native'
import { UserIcon, ChevronDownIcon, AdjustmentsVerticalIcon, MagnifyingGlassIcon } from 'react-native-heroicons/outline'
import Categories from '../components/Categories'
import FeaturedRow from '../components/FeaturedRow'
import SafeViewAndroid from "../components/SafeViewAndroid";
import sanityClient from '../sanity'

const HomeScreen = () => {
    const navigation = useNavigation();
    const [featuredCategories, setFeaturedCategories] = useState([]);


    useLayoutEffect(() => {
        navigation.setOptions({
            headerShown: false,
        })
    }, [])

    useEffect(() => {
        sanityClient.fetch(`
        *[_type == 'featured'] {
            ..., restaurants[] -> {
                ...,dishes[] -> {
                    ...
                }
            }
        }
        `).then(data => {
            setFeaturedCategories(data);
        })
    }, [])
    
    return (
        <SafeAreaView style={ SafeViewAndroid.AndroidSafeArea }>


            {/* Header */ }
            <View className="flex-row pb-3 items-center mx-4 space-x-2 py-2">


                <Image
                    source={ {
                        uri: "https://media.istockphoto.com/id/1250495017/vector/courier-rides-a-bicycle-on-a-city.jpg?s=612x612&w=0&k=20&c=PAulV7kSoz91X-p1Hm0v_fTNSxtSLJIiLVSFa8r-mqI=",
                    } }

                    className='h-9 w-9 bg-gray-300 rounded-full'

                />
                <View className="flex-1">
                    <Text className="font-bold text-gray-400 text-xs">Deliver Now</Text>
                    <Text className="font-bold text-xl">Current Location

                        <ChevronDownIcon style={styles.chevIcon} size={ 20 } color="#00CCBB" />
                    </Text>
                    
                </View>
                <UserIcon size={ 35 } color="#00CCBB" />

            </View>
            {/* Search */ }
            <View className="flex-row items-center space-x-2 pb-2 mx-4">

                <View className="flex-row space-x-2 flex-1 bg-gray-200 p-3 rounded-lg">
                    <MagnifyingGlassIcon color="#00CCBB" />
                    <TextInput
                        className="p-0"

                        placeholder="Restaurants and cuisines"
                        placeholderTextColor="gray"
                        keyboardType="default"
                    />
                </View>

                <AdjustmentsVerticalIcon size={30} color="#00CCBB" />
            </View>

            {/* Body */ }
            <ScrollView className="bg-gray-100">
                {/* Categories */ }


                <Categories />
                {/* Featured Rows */ }
                { featuredCategories?.map((category) => {
                    return (<FeaturedRow
                        key={category._id}
                        id={ category._id }
                        title={category.name}
                        description={category.shortDescription}
                        
                    />
                    )
                })}
                
            </ScrollView>
        </SafeAreaView>
    )
}

const styles = StyleSheet.create({
    chevIcon: {
        display: Platform.OS === 'web' ? 'inline' : 'flex'
    },
})
  

export default HomeScreen

