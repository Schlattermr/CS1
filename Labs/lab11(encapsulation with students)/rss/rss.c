/**
 * Author: Matt Schlatter
 * Date: 2022-11-07
 *
 * Utilizes Rss structure to display article titles,
 * links, descriptions, and dates
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "rss.h"

char *deepStringCopy(const char *source) {
    if(source == NULL) {
        return NULL;
    }

    char *deepCpy = (char *) malloc ((strlen(source) + 1) * sizeof(char));
    strcpy(deepCpy, source);

    return deepCpy;
}

Rss *createEmptyRss() {
    Rss *rss = (Rss *)malloc(sizeof(Rss));
    rss->title = "";
    rss->link = "";
    rss->description = "";
    rss->date = "";

    return rss;
}

Rss *createRss(const char *title,
               const char *link,
               const char *date,
               const char *description) {
    if(title == NULL || link == NULL || date == NULL || description == NULL) {
        return NULL;
    }

    Rss *rss = (Rss *)malloc(sizeof(Rss));
    initRss(rss, title, link, date, description);
    return rss;
}

void initRss(Rss *feed,
             const char *title,
             const char *link,
             const char *date,
             const char *description) {
    if(feed == NULL || title == NULL || link == NULL || date == NULL || description == NULL) {
        return;
    }
    feed->title = deepStringCopy(title);
    feed->link = deepStringCopy(link);
    feed->date = deepStringCopy(date);
    feed->description = deepStringCopy(description);

    return;
}

void printRss(const Rss *item) {
    if(item == NULL) {
        return;
    }

    printf("<channel>\n");
    printf("\t<title>%s</title>\n", item->title);
    printf("\t<link>%s</link>\n", item->link);
    printf("\t<description>%s</description>\n", item->description);
    printf("\t<date>%s</date>\n", item->date);
    printf("\t<item>\n");
    free(item->title);
    free(item->link);
    free(item->description);
    free(item->date);

    return;
}