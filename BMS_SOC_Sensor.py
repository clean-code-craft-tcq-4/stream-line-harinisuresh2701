import random
from random import randint

number_of_samples = 50
min_SOC_value_in_percent = 0
max_SOC_value_in_percent = 100
def SOC_sensor_data_generator(number_of_samples,min_SOC_value_in_percent,max_SOC_value_in_percent):
    SOC_samples = []
    for i in range(number_of_samples):
        SOC_samples.append(random.randint(min_SOC_value_in_percent,max_SOC_value_in_percent))
    return SOC_samples
