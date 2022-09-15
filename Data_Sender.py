import random
from random import randint
number_of_samples = 50

def Sensor_data_generator(number_of_samples,min_sensor_value,max_sensor_value):
    Sensor_Samples = []
    for i in range(number_of_samples):
        Sensor_Samples.append(random.randint(min_sensor_value,max_sensor_value))
    return Sensor_Samples
  
def fetch_data_from_sensors(number_of_samples):
  Data_from_SOC_Sensor = Sensor_data_generator(number_of_samples,0,100)
  Data_from_Temp_Sensor = Sensor_data_generator(number_of_samples,0,45)
  return Data_from_SOC_Sensor, Data_from_Temp_Sensor
  
def format_data_in_JSON(sample_no,Sensor_1,Sensor_1_value,Sensor_2,Sensor_2_value):
  data_in_JSON = ('{{{0}:{1}, {2}:{3}, {4}:{5}}}\n'.format("Sample_no",sample_no,Sensor_1,Sensor_1_value,Sensor_2,Sensor_2_value))
  return data_in_JSON
  
def print_data_on_console(data):
  print(data)
  
def consolidate_sensor_data_on_console(number_of_samples):
  data_from_sensor = fetch_data_from_sensors(number_of_samples)
  for i in range(number_of_samples):
    consolidated_data = format_data_in_JSON(i,"SOC Sensor",data_from_sensor[0][i],"Temperature Snsor",data_from_sensor[1][i])
    print_data_on_console(consolidated_data)

def main():
  consolidate_sensor_data_on_console(number_of_samples)
if __name__ == '__main__':
  main()
