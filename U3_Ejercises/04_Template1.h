
int maximum (int value1, int value2, int value3){
    int maximumValue = value1;

    if (value2 > maximumValue){
        maximumValue = value2;
    }
    if (value2 > maximumValue){
        maximumValue = value3;
    }
    return maximumValue;
}

int minimum (int value1, int value2, int value3){
    int maximumValue = value1;

    if (value2 < maximumValue){
        maximumValue = value2;
    }
    if (value2 < maximumValue){
        maximumValue = value3;
    }
    return maximumValue;
}