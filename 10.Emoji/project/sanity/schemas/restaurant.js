import {defineField, defineType} from 'sanity'

export default defineType({
  name: 'restaurant',
  title: 'Restaurant',
  type: 'document',
  fields: [
    defineField({
      name: 'restaurantName',
      title: 'Restaurant name',
      type: 'string',
      validation: (rule) => rule.required(),
    }),
    defineField({
      name: 'shortDescription',
      title: 'Short Description',
      type: 'string',
      validation: (rule) => rule.max(200),
    }),
    defineField({
      name: 'image',
      title: 'Image of the Restaurant',
      type: 'image'
    }),
    defineField({
      name: 'address',
      title: 'Restaurant Address',
      type: 'string',
      validation: (rule) => rule.required(),
    }),
    defineField({
      name: 'latitude',
      title: 'Latitude of the Restaurant',
      type: 'number'
    }),
    defineField({
      name: 'longitude',
      title: 'Longitude of the Restaurant',
      type: 'number'
    }),
    defineField({
      name: 'type',
      title: 'Category',
      validation: rule => rule.required(),
      
      type: 'reference',
      to:[{type: 'category'}]
    }),
    defineField({
      name: 'dishes',
      title: 'Dishes',
      validation: rule => rule.required(),
      
      type: 'array',
      of: [{type:'reference', to:[{type:'dish'}]}]
    }),

    defineField({
      name: 'rating',
      title: 'Enter a Rating from (1-5) stars.',
      type: 'number',
      validation: rule => rule.required().min(1).max(5).error('Please enter a value between 1 and 5.')
    }),
  ],
})
 