### Problem Analysis Chart (PAC)

| Given Data | Required Results |
| :--- | :--- |
| • Total number of guests (`N`)<br>• Season (`season`: 1 for Peak, 2 for Off-Peak)<br>• Room type (`room_type`: 1 for Standard, 2 for Deluxe, 3 for Suite)<br>• Nights stayed (`nights`)<br>• Rate table (Peak: 5k/8k/12k, Off-Peak: 3k/5k/8k)<br>• Flat 15% discount rule for `nights > 7` | • Final bill for each guest (`final_price`)<br>• Total Hotel Revenue (`total_revenue`) |
| **Processing Required** | **Solution Alternatives** |
| • Determine `rate` using nested decisions on `season` and `room_type`<br>• `base_total = rate * nights`<br>• If `nights > 7`, `discount = base_total * 0.15`, else `discount = 0.0`<br>• `final_price = base_total - discount`<br>• `total_revenue = total_revenue + final_price` | 1. Calculate and display each guest's bill individually without accumulating total revenue.<br>*2. Use a loop for `N` guests to calculate individual bills and continuously accumulate `total_revenue`. |
