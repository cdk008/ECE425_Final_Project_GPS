# ECE 425 - GPS Utilization Using UART
**By Cody Krueger**

**Instructor Aaron Nanas**

**CSU Northridge**

**Department of Electrical and Computer Engineering**

## Introduction

The goal of this project is to successfully read the output of an off the shelf GPS module using the TIVA TM4C123G Launchpad microcontroller. The ability to do so allows for future projects that are not reliant on using predetermined ecosystems but take advantage of the convenience of commercial components. This means that flexibility can be gained where necessary on a given project without building everything from scratch. While the GPS used in this project has many features and settings, the goal of this project is to get and understand the base output.

## Results and Video Demonstration Links

The output for the project was the printed output of the GPS module in a TeraTerm terminal shown below. Most of the results provide information that goes into the quality of the track, the satellites and constellations that were used along with the time the result was received. The lines that show the latitude and longitude are GNGLL and GNRMC. In the example shown, the latitude is shown first with 3534.13381 N with the 35 being the degrees, 34 the minutes and 13.381 being the seconds in the northern hemisphere. The longitude was shown next with the 117 showing the degrees, 32 minutes and 81.038 seconds in the western hemisphere. 

### INSERT IMAGE HERE

When plugging in the coordinates into a mapping software, the exact numbers were not coming up with results. This seemed to be due to the fact that the mapping softwares did not accept the significant figures from the GPS. There also was a discrepancy between the GPS output and a smartphone GPS location. Due to the maps softwares not accepting the exact coordinates, it is hard to determine what error is due to either gps or to the mapping software itself. The image below shows the difference in Bing Maps as this is the one that accepted the coordinates most accurately.

GPS: 35°34'13.4"N 117°32'81.0"W 
Phone: 35°34'08.2"N 117°32'49.4"W

### INSERT IMAGE HERE

The main challenges included finding information for the GPS module and getting the outputs to display properly. I was not able to find a data sheet for the GPS module and ended up having to settle for a product page that had enough information. While this helped verify that the GPS on the device used UART and gave a range of baud rates, it did not give a definitive default to go off of or give instructions for how to set up a specific baud rate or change any of the settings for the GPS. I was able to determine that the default baud rate was 9600 and adjust the microcontroller programming to match. After getting an output, I had to alter the maximum size of the message that could come in as my initial guess of 64 characters was too small and lead to overwriting of the data.

[Link](https://youtu.be/P0uv83bj6EU) to video showing GPS cold startup

[Link](https://youtu.be/dxJiQWxAOfA) to video showing GPS 3D-Lock

## Background and Methodology

The primary embedded system concept that is used in this project, as highlighted in the title of the project, is UART communication protocol. UART or Universal Asynchronous Receiver Transmitter uses two wires between two devices along with agreed upon parameters such as baud rate. In order to set up and make the necessary connections, GPIO and delays were also used. The hardware used in this project includes a Mateksys M8Q-5883 GPS module, the TM4C123GH6PM microcontroller, and a Elegoo 5V power supply. The microcontroller peripherals used included UART, SysTick and GPIO. The data output from the microcontroller was displayed on a laptop using TeraTerm software.

## Block Diagram

### INSERT IMAGE HERE

## Components Used

| Component | Quantity | Price | Link |
| --------- | :------: | :---: | ---- |
| Mateksys M8Q-5883 GPS module | 1 | $49.89 | [GPS Link](https://www.aliexpress.us/item/3256802785524369.html?src=google&pdp_npi=4%40dis%21USD%2149.89%2149.89%21%21%21%21%21%40%2112000023019634973%21ppc%21%21%21&src=google&albch=shopping&acnt=708-803-3821&isdl=y&slnk=&plac=&mtctp=&albbt=Google_7_shopping&aff_platform=google&aff_short_key=UneMJZVf&gclsrc=aw.ds&albagn=888888&ds_e_adid=&ds_e_matchtype=&ds_e_device=c&ds_e_network=x&ds_e_product_group_id=&ds_e_product_id=en3256802785524369&ds_e_product_merchant_id=101006615&ds_e_product_country=US&ds_e_product_language=en&ds_e_product_channel=online&ds_e_product_store_id=&ds_url_v=2&albcp=19158444193&albag=&isSmbAutoCall=false&needSmbHouyi=false&gad_source=1&gclid=Cj0KCQiApNW6BhD5ARIsACmEbkWsc4HhrDFkB1u_Q3X64rlleNMHPQ3z6ci4ZOPpNu6r2ECnmDCgKaoaAkKsEALw_wcB&gatewayAdapt=glo2usa) |
| Tiva TM4C123GXL Launchpad | 1 | $27.19 | [Lauchpad Link](https://www.aliexpress.us/item/3256807251491775.html?src=google&pdp_npi=4%40dis%21USD%2127.25%2127.25%21%21%21%21%21%40%2112000040754373961%21ppc%21%21%21&src=google&albch=shopping&acnt=708-803-3821&isdl=y&slnk=&plac=&mtctp=&albbt=Google_7_shopping&aff_platform=google&aff_short_key=UneMJZVf&gclsrc=aw.ds&albagn=888888&ds_e_adid=&ds_e_matchtype=&ds_e_device=c&ds_e_network=x&ds_e_product_group_id=&ds_e_product_id=en3256807251491775&ds_e_product_merchant_id=5295126550&ds_e_product_country=US&ds_e_product_language=en&ds_e_product_channel=online&ds_e_product_store_id=&ds_url_v=2&albcp=20268592310&albag=&isSmbAutoCall=false&needSmbHouyi=false&gad_source=1&gclid=Cj0KCQiApNW6BhD5ARIsACmEbkVMz8SkxmHnLqJF4rAMK0Km9gdcjBfSw7_Qp4OmyIHREMPk3HYHKBEaAqoAEALw_wcB&gatewayAdapt=glo2usa) |
Elegoo 5V power supply | 1 | $0.63 | [Power Supply Link](https://www.aliexpress.us/item/3256802497196686.html?src=google&pdp_npi=4%40dis%21USD%210.71%210.64%21%21%21%21%21%40%2112000021705296223%21ppc%21%21%21&src=google&albch=shopping&acnt=708-803-3821&isdl=y&slnk=&plac=&mtctp=&albbt=Google_7_shopping&aff_platform=google&aff_short_key=UneMJZVf&gclsrc=aw.ds&albagn=888888&ds_e_adid=&ds_e_matchtype=&ds_e_device=c&ds_e_network=x&ds_e_product_group_id=&ds_e_product_id=en3256802497196686&ds_e_product_merchant_id=5495093922&ds_e_product_country=US&ds_e_product_language=en&ds_e_product_channel=online&ds_e_product_store_id=&ds_url_v=2&albcp=19158444193&albag=&isSmbAutoCall=false&needSmbHouyi=false&gad_source=1&gclid=Cj0KCQiApNW6BhD5ARIsACmEbkXfT-x3KpfsUKYsi6vWvkUTVDwYpkCBBCMfCVl2-MUdUcBj8NgyXGwaAg3yEALw_wcB&gatewayAdapt=glo2usa) |



## Pinout Used

| Function | Pin |
| --------- | ---- |
| UART0 Rx connection to laptop | PA0 |
| UART0 Tx connection to laptop | PA1 |
| UART1 Rx connection to GPS | PB0 |
| UART1 Tx connection to GPS | PB1 |

