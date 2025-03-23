/*
 * 🚨 WARNING: CHALLENGE MODE ACTIVATED 🚨
 * 
 * 1️⃣ Sit back, take a deep breath, and **THINK**.
 * 2️⃣ For the next **10 minutes**, avoid using **Gen AI, ChatGPT, or any shortcuts**.
 * 3️⃣ Trust your **brain**—you’re smarter than you think!
 * 4️⃣ Consider yourself a **LOSER** if you cheat. Seriously, promise yourself you won't. 😤
 * 5️⃣ If you solve it on your own, **you WIN** and level up as a true programmer and come and meet me ! 
 * 
 * 
 * 💡 Remember: The best coders aren’t the ones who copy-paste. They are the ones who **struggle, think, fail, and then succeed.** 
 *    
 * Now, write your code! You got this! 💪🔥
 */

 #include <stdio.h>

#define MAX_ROOMS 5  

void initializeSystem(int roomnum, int lightSystem[], int temperatureSensors[], int motionSensors[], int securityLocks[]);
void displayMenu();
void controlLights(int roomnum, int lightSystem[]);
void readTemperature(int roomnum, int temperatureSensors[]);
void detectMotion(int roomnum, int motionSensors[], int noMotionCount[], int securityLocks[]);
void securitySystem(int roomnum, int securityLocks[]);
void analyzeHouseStatus(int roomnum, int lightSystem[], int temperatureSensors[], int motionSensors[], int securityLocks[]);

int main() {
    int roomnum;
    int lightSystem[MAX_ROOMS] = {0};
    int temperatureSensors[MAX_ROOMS];
    int motionSensors[MAX_ROOMS] = {0};
    int securityLocks[MAX_ROOMS] = {1, 1, 0, 1, 1};
    int noMotionCount[MAX_ROOMS] = {0};

    printf("Enter number of rooms: ");
    scanf("%d", &roomnum);

    if (roomnum > MAX_ROOMS) {
        printf("Maximum 5 rooms only allowed. Setting to maximum.\n");
        roomnum = MAX_ROOMS;
    } else {
        printf("Initializing system...\n\n");
    }

    initializeSystem(roomnum, lightSystem, temperatureSensors, motionSensors, securityLocks);

    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: controlLights(roomnum, lightSystem); break;
            case 2: readTemperature(roomnum, temperatureSensors); break;
            case 3: detectMotion(roomnum, motionSensors, noMotionCount, securityLocks); break;
            case 4: securitySystem(roomnum, securityLocks); break;
            case 5: analyzeHouseStatus(roomnum, lightSystem, temperatureSensors, motionSensors, securityLocks); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice, try again.\n");
        }
    } while (choice != 6);

    return 0;
}

void initializeSystem(int roomnum, int lightSystem[], int temperatureSensors[], int motionSensors[], int securityLocks[]) {
    for (int i = 0; i < roomnum; i++) {
        temperatureSensors[i] = 22 + (i % 5);
    }
    motionSensors[1] = 1;
}

void displayMenu() {
    printf("\n===== Smart Home Menu =====\n");
    printf("1. Toggle Light\n");
    printf("2. Read Temperature\n");
    printf("3. Check Motion Sensor\n");
    printf("4. Lock/Unlock Security System\n");
    printf("5. House Status Summary\n");
    printf("6. Exit\n");
}

void controlLights(int roomnum, int lightSystem[]) {
    int room;
    printf("Enter room number to toggle light (1-%d): ", roomnum);
    scanf("%d", &room);

    if (room >= 1 && room <= roomnum) {
        lightSystem[room - 1] = !lightSystem[room - 1];
        printf("Light in Room %d is now %s.\n\n", room, lightSystem[room - 1] ? "ON" : "OFF");
    } else {
        printf("Invalid room number.\n");
    }
}

void readTemperature(int roomnum, int temperatureSensors[]) {
    int room;
    printf("Enter room number (1-%d) to read temperature: ", roomnum);
    scanf("%d", &room);

    if (room >= 1 && room <= roomnum) {
        printf("Temperature in Room %d: %d°C\n", room, temperatureSensors[room - 1]);
        if (temperatureSensors[room - 1] > 30) {
            printf("WARNING: High temperature detected in Room %d!\n", room);
        }
    } else {
        printf("Invalid room number.\n");
    }
}

void detectMotion(int roomnum, int motionSensors[], int noMotionCount[], int securityLocks[]) {
    int room;
    printf("Enter room number (1-%d) to check motion sensor: ", roomnum);
    scanf("%d", &room);
    
    if (room >= 1 && room <= roomnum) {
        printf("Motion in Room %d: %s\n", room, motionSensors[room - 1] ? "Detected" : "None");
        if (motionSensors[room - 1]) {
            noMotionCount[room - 1] = 0;
        } else {
            noMotionCount[room - 1]++;
            if (noMotionCount[room - 1] >= 5) {
                securityLocks[room - 1] = 1;
                printf("Room %d has been auto-locked due to inactivity.\n", room);
            }
        }
    } else {
        printf("Invalid room number.\n");
    }
}

void securitySystem(int roomnum, int securityLocks[]) {
    int room;
    printf("Enter room number (1-%d) to toggle lock: ", roomnum);
    scanf("%d", &room);
    
    if (room >= 1 && room <= roomnum) {
        securityLocks[room - 1] = !securityLocks[room - 1];
        printf("Room %d is now %s.\n", room, securityLocks[room - 1] ? "Locked" : "Unlocked");
    } else {
        printf("Invalid room number.\n");
    }
}

void analyzeHouseStatus(int roomnum, int lightSystem[], int temperatureSensors[], int motionSensors[], int securityLocks[]) {
    printf("\nHouse Status:\n\n");
    for (int i = 0; i < roomnum; i++) {
        printf("- Room %d: Light %s, Temp %d°C, %s, %s\n",
               i + 1,
               lightSystem[i] ? "ON" : "OFF",
               temperatureSensors[i],
               motionSensors[i] ? "Motion Detected" : "No Motion",
               securityLocks[i] ? "Locked" : "Unlocked");
    }
    printf("\n");
}