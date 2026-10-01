#include <stdio.h>

struct SmartDevice {
    int deviceID;
    char deviceName[50];
    int status;
    float ratedPowerKW;
};

struct EnergySensor {
    float voltageVolts;
    float currentAmperes;
    int unoccupancyMinutes;
};

int main() {
    struct SmartDevice device;
    struct EnergySensor sensor;

    float operatingHours;
    float energy;
    float cost = 0;

    printf("Nhap ma thiet bi: ");
    scanf("%d", &device.deviceID);

    printf("Nhap ten thiet bi: ");
    scanf("%s", device.deviceName);

    printf("Nhap trang thai (1-Bat, 0-Tat): ");
    scanf("%d", &device.status);

    printf("Nhap cong suat dinh muc (kW): ");
    scanf("%f", &device.ratedPowerKW);

    printf("Nhap dien ap (V): ");
    scanf("%f", &sensor.voltageVolts);

    printf("Nhap dong dien (A): ");
    scanf("%f", &sensor.currentAmperes);

    printf("Nhap thoi gian vang nguoi (phut): ");
    scanf("%d", &sensor.unoccupancyMinutes);

    printf("Nhap so gio hoat dong trong thang: ");
    scanf("%f", &operatingHours);

    if (sensor.voltageVolts < 0 ||
        sensor.currentAmperes < 0 ||
        sensor.unoccupancyMinutes < 0) {

        printf("Loi: Du lieu cam bien khong hop le!\n");
        return 0;
    }

    if (operatingHours <= 0 || operatingHours > 744) {
        printf("Loi: Thoi gian van hanh khong hop le!\n");
        return 0;
    }

    if (sensor.currentAmperes > 30.0f) {
        device.status = 0;
        printf("CANH BAO: Dong dien qua tai! Nguy co chay no.\n");
    } else if (device.status == 1 &&
               sensor.unoccupancyMinutes >= 15) {
        device.status = 0;
        printf("Tu dong tat thiet bi do phong vang nguoi.\n");
    }

    energy = device.ratedPowerKW * operatingHours;

    if (energy <= 50) {
        cost = energy * 1806;
    } else if (energy <= 100) {
        cost = 50 * 1806 + (energy - 50) * 1866;
    } else if (energy <= 200) {
        cost = 50 * 1806 + 50 * 1866 + (energy - 100) * 2167;
    } else {
        cost = 50 * 1806 + 50 * 1866 + 100 * 2167
             + (energy - 200) * 2729;
    }

    printf("\n=== BAO CAO ===\n");
    printf("Ma thiet bi: %d\n", device.deviceID);
    printf("Ten thiet bi: %s\n", device.deviceName);
    printf("Trang thai: %s\n", device.status ? "BAT" : "TAT");
    printf("Dien nang: %.2f kWh\n", energy);
    printf("Tien dien: %.0f VND\n", cost);

    return 0;
}
