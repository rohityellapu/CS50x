import { defineField, defineType } from 'sanity'

export default defineType({
    name: 'featured',
    title: 'Featured Menu categories',
    type: 'document',
    fields: [
        defineField({
            name: 'name',
            title: 'Featured Category name',
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
            name: 'restaurants',
            title: 'Restuarants',
            type: 'array',
            of: [{ type: 'reference', to: [{ type: 'restaurant' }] }]
        }),
    ],
})
