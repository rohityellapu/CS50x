// const sanityClient = require('@sanity/client')
// const imageUrlBuilder = require('@sanity/image-url')

import sanityClient  from '@sanity/client';
import imageUrlBuilder from '@sanity/image-url'

const client = sanityClient({
    projectId: 'bs53q77o',
    dataset: 'production',
    apiVersion: '2022-12-12', // use current UTC date - see "specifying API version"!
    // token: 'sanity-auth-token', // or leave blank for unauthenticated usage
    useCdn: true, // `false` if you want to ensure fresh data
})

const builder = imageUrlBuilder(sanityClient)
export const urlFor = (source) => builder.image(source);

export default client;

