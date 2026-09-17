### Problem Analysis Chart (PAC)

| Given Data | Required Results |
| :--- | :--- |
| • Total number of guests (`N`)<br>• Season (`season`: 1 for Peak, 2 for Off-Peak)<br>• Room type (`room_type`: 1 for Standard, 2 for Deluxe, 3 for Suite)<br>• Nights stayed (`nights`)<br>• Rate table (Peak: 5k/8k/12k, Off-Peak: 3k/5k/8k)<br>• Flat 15% discount rule for `nights > 7` | • Final bill for each guest (`final_price`)<br>• Total Hotel Revenue (`total_revenue`) |
| **Processing Required** | **Solution Alternatives** |
| • Determine `rate` using nested decisions on `season` and `room_type`<br>• `base_total = rate * nights`<br>• If `nights > 7`, `discount = base_total * 0.15`, else `discount = 0.0`<br>• `final_price = base_total - discount`<br>• `total_revenue = total_revenue + final_price` | 1. Calculate and display each guest's bill individually without accumulating total revenue.<br>*2. Use a loop for `N` guests to calculate individual bills and continuously accumulate `total_revenue`. |

### Input-Processing-Output (IPO) Chart

| Input | Processing | Module Reference | Output |
| :--- | :--- | :--- | :--- |
| • Number of guests (`N`)<br>• Season (`season`)<br>• Room type (`room_type`)<br>• Nights stayed (`nights`) | 1. Initialize `total_revenue = 0`<br>2. Enter total guests (`N`)<br>3. Loop `guest` from 1 to `N`<br>4. Enter `season`, `room_type`, `nights`<br>5. Determine `rate` via season & room type<br>6. Calculate `base_total = rate * nights`<br>7. Calculate `discount` if `nights > 7`<br>8. Calculate `final_price = base_total - discount`<br>9. Calculate `total_revenue = total_revenue + final_price`<br>10. Print `final_price`<br>11. End Loop<br>12. Print `total_revenue`<br>13. End | Initialize<br>Read<br>Loop<br>Read<br>Selection<br>Calc<br>Selection<br>Calc<br>Calc<br>Print<br>Loop<br>Print<br>HotelBookingControl | • Guest final price (`final_price`)<br>• Total Hotel Revenue (`total_revenue`) |
