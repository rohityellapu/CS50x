import { ScrollView } from 'react-native'
import React, {useState, useEffect} from 'react'
import CategoryCard from './CategoryCard'
import sanityClient from '../sanity'

const Categories = () => {
  const [categories, setCategories] = useState([])
  useEffect(() => {
    sanityClient.fetch(`
    *[_type == "category"] {
      
      "imageUrl": image.asset->url,
      ...
    }
    `).then(data => setCategories(data))
  },[])
  
  return (
      <ScrollView
          horizontal
          showsHorizontalScrollIndicator={ false }
          contentContainerStyle={ {
              paddingHorizontal: 15,
              paddingTop:10
          }}
      >
          {/* Category Card */ }
      { categories?.map(category => (
        <CategoryCard key={category._id} imgUrl={ category.imageUrl } title={ category.name } />
            
          ))}
          

    </ScrollView>
      
    
  )
}

export default Categories