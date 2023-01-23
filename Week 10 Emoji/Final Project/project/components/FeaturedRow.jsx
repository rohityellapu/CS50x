import { View, Text, ScrollView } from 'react-native'
import React, {useState, useEffect} from 'react'
import { ArrowRightIcon } from 'react-native-heroicons/outline'
import sanityClient, { urlFor } from '../sanity'
import RestaurantCard from './RestaurantCard'
const FeaturedRow = ({ id, title, description }) => {

    const [restaurants, setRestaurants] = useState([])
    useEffect(() => {
        sanityClient.fetch(`
        *[_type == 'featured' && _id == $id] {
            ..., restaurants[] -> {
                "imageUrl": image.asset->url,
                ..., dishes[] -> {
                        "imageUrl": image.asset->url,
                        ...
                    },
                    type-> {
                       name 
                    },
                }
            }[0]
        `, { id }).then(data => setRestaurants(data?.restaurants));
    }, [])
    
    return (
        <View>
            <View className="mt-4 flex-row items-center justify-between px-4">
                <Text className="font-bold text-lg">{ title }</Text>

                <ArrowRightIcon color='#00CCBB' />
            </View>
            <Text className="text-xs text-gray-400 px-4">{ description }</Text>
            <ScrollView
                horizontal
                showsHorizontalScrollIndicator={ false }
                contentContainerStyle={ {
                    paddingHorizontal: 15,

                } }
                className='pt-4'>
                {/* map */ }
                { restaurants?.map((restaurant) => {
                    return (

                        <RestaurantCard
                            id={ restaurant._id }
                            key={restaurant._id}
                            imgUrl={ restaurant.imageUrl }
                            img={restaurant.image}
                            title={restaurant.restaurantName}
                            rating={ restaurant.rating }
                            genre={restaurant.type?.name}
                            address={restaurant.address}
                            description={restaurant.shortDescription}
                            dishes={ restaurant.dishes }
                            long={ restaurant.latitude}
                            lat={restaurant.longitude}
                            />
                    )
                })}

            </ScrollView>
        </View>
    )
}

export default FeaturedRow