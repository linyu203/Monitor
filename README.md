# Monitor
## Monitor
   The project was designed to practice building a C++ project associate with the design pattern, and polymophic features.  
   Here, also implememt the project with the Golang and Python, to familize and improve the Python and Golang.

### Description
   MonitorProj is trying to build a tool to monitor the market transection records, and to check if there are any rules were violated by reading the event records  
  * The events has 3 types:  
   PRICE:    PRICE|DATE|TIME|PARSEKEY|PRICE  
   ORDER:    ORDER|ORDER ID|DATE|TIME|CLIENT|BROKER|BUY or SELL|PARSEKEY|VOLUME|PRICE  
   EXECUTE:  EXECUTE|ORDER ID|DATE|TIME|CLIENT|BROKER|BUY or SELL|PARSEKEY|VOLUME|PRICE 
  * example:  
   PRICE|20200220|10:20:34|GOOGL US EQUITY|2210.5  
   ORDER|301|20200313|15:30:45|KATE|GOLDMEN|BUY|GOOGL US EQUITY|200|2213.2  
   EXECUTE|301|20200314|09:25:00|KATE|GOLDMEN|BUY|GOOGL US EQUITY|200|2213
   
There are some rules to check each event, if the event violate the rule, should report or do some other action to present the warning, 
should easily adding new rules, and the actions should be easily to switch

- rule 1. io: executed order id not placed
- rule 2. em: fields in executed order not match with the original order
- rule 3. ose: exeucted volume (accumulated) is larger than the original required volume
- rule 4. ode: the order executed after the order was expired
- rule 5. sfp: the client sold the securities for profit with in 30 days
- rule 6. ap: the securities sold or bought in a price that over 200% of the market price, or less than 50%
- rule 7. dmn: a broker has deal over 50% of the average trancetion for a security
+ rule 8. wildcare rules: any rule could be added into, should support to add new rules

To run the tool:
...$ ./monitorProj ../testCase/dmn.dat
