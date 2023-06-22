#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LINE_LENGTH 100

typedef struct {
    int entryNo;
    char sensorNo[10];
    float temperature;
    int humidity;
    int light;
    char time[10];
} LogEntry;

void displayLogEntries(const LogEntry* logEntries, int count) {
    printf("EntryNo\tSensorNo\tTemperature\tHumidity\tLight\tTime\n");
    printf("--------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t\t%.1f\t\t%d\t\t%d\t%s\n",
               logEntries[i].entryNo,
               logEntries[i].sensorNo,
               logEntries[i].temperature,
               logEntries[i].humidity,
               logEntries[i].light,
               logEntries[i].time);
    }
}

int main() {
    LogEntry logEntries[MAX_ENTRIES];
    int count = 0;

    FILE* file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];

    // Skip the header line
    fgets(line, sizeof(line), file);

    while (count < MAX_ENTRIES && fgets(line, sizeof(line), file) != NULL) {
        sscanf(line, "%d,%[^,],%f,%d,%d,%[^,\n]",
               &logEntries[count].entryNo,
               logEntries[count].sensorNo,
               &logEntries[count].temperature,
               &logEntries[count].humidity,
               &logEntries[count].light,
               logEntries[count].time);

        count++;
    }

    fclose(file);

    displayLogEntries(logEntries, count);

    return 0;
}