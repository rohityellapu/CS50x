import {defineField, defineType} from 'sanity'

export default defineType({
  name: 'dish',
  title: 'Dish',
  type: 'document',
  fields: [
    defineField({
      name: 'name',
      title: 'Name of the Dish',
      type: 'string',
      validation: rule => rule.required()
    }),
    defineField({
      name: 'shortDescription',
      title: 'Short description',
      type: 'string',
      validation: rule => rule.max(200)
    }),
    defineField({
      name: 'price',
      title: 'Price of the dish in GDP',
      type: 'number',
    }),
    defineField({
      name: 'image',
      title: 'Image of the dish.',
      type: 'image',
    }),
  ]
    
})
