import random
from random import randint

number_of_samples = 50
min_Temp_in_Celsius = 0
max_Temp_in_Celsius = 45
def Temp_sensor_data_generator(number_of_samples,min_Temp_in_Celsius,max_Temp_in_Celsius):
    Temp_samples = []
    for i in range(number_of_samples):
        Temp_samples.append(random.randint(min_Temp_in_Celsius,max_Temp_in_Celsius))
    return Temp_samples
