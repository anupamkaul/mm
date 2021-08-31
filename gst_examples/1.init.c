/* before gstreamer libraries can be used, gst_init has to be called from the main application.
 * This call will perform the necessary initiations of the library as well as parse the gstreamer specific command line options
*/

#include <stdio.h>
#include <gst/gst.h>

int main (int argc, char *argv[]) 
{

    const gchar *nano_str;
    guint major, minor, micro, nano;

    gst_init (&argc, &argv); // transfer parameters over

    gst_version(&major, &minor, &micro, &nano); // get version

    if (nano==1)
        nano_str = "(CVS)";
    else if (nano==2)
        nano_str = "(Prerelease)";
    else
        nano_str = "";

    printf("This program is linked against GStreamer %d.%d.%d %s\n", major, minor, micro, nano_str);
    return 0;
}
