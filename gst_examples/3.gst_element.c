/* elements are basic building blocks in gstreamer. Elements can stand for Source elements (read from file/disk), Filters, convertors,
 * demuxers, muxers and codecs (usually with src and sink funcs), Sink elements (with sink blocks) that will connect with Pads, or anything else.
 *
 * An element is the most important class of objects in GStreamer. 
 * You will usually create a chain of elements linked together and let data flow through this chain of elements. 
 * An element has one specific function, which can be the reading of data from a file, decoding of this data,
 * or outputting this data to your sound card (or anything else). 
 *
 * By chaining together several such elements, you create a pipeline that can do a specific task, for example media playback (decode) or capture (encode). 
 * GStreamer ships with a large collection of elements by default, making the development of a large variety of media applications possible. 
 * If needed, you can also write new elements. (See https://gstreamer.freedesktop.org/documentation/plugin-development/index.html?gi-language=c)


 * The simplest way to create an element is to use gst_element_factory_make (). 
 * This function takes a factory name and an element name for the newly created element. 
 * The name of the element is something you can use later on to look up the element in a bin, for example. 
 * The name will also be used in debug output. You can pass NULL as the name argument to get a unique, default name.

 * When you don't need the element anymore, you need to unref it using gst_object_unref (). 
 * This decreases the reference count for the element by 1. 
 * An element has a refcount of 1 when it gets created. An element gets destroyed completely when the refcount is decreased to 0.

 * The following example shows how to create an element named source from the element factory named fakesrc.
 * It checks if the creation succeeded. After checking, it unrefs the element.
 *
 */


#include <stdio.h>
#include <gst/gst.h>

int main(int argc, char *argv[]) {

    GstElement *element;

    /* init GStreamer */
    gst_init(&argc, &argv);

    /* create element */
    element = gst_element_factory_make ("fakesrc", "source");
    if (!element) {
        g_print ("Failed to create element of type 'fakesrc'\n");
        return -1;
    }

    /* used, now de-refcount/unref it */
    gst_object_unref (GST_OBJECT (element));
    g_print("created and unref'ed 'fakesrc' element\n");

    return 0;
}

