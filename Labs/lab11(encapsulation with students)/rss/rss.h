/**
 * Provides title, link, description, and publication
 * date for a UNL RSS feed from XML data
 */
typedef struct {
    char *title;
    char *link;
    char *description;
    char *date;
} Rss;

/**
 * Returns a deep copy of the given string
 */
char *deepStringCopy(const char *source);

/**
 * A factory function to create an empty RSS feed
 * with "default" values
 */
Rss *createEmptyRss();

/**
 * A factory function to create an Rss structure
 * with the given values
 */
Rss *createRss(const char *title,
               const char *link,
               const char *date,
               const char *description);

/**
 * An initialization function to initialize an RSS feed with the
 * given values.
 */
void initRss(Rss *feed,
             const char *title,
             const char *link,
             const char *date,
             const char *description);

/**
 * A function that prints the given Rss structure
 * to the standard output.
 */
void printRss(const Rss *item);