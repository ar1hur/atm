# ATM

playing around with c++ and dependency injection kind of

shows how you can use dependency injection with an interface to be able to extend any further depot saving mechanisms. I took me a while to figure it out.

# how it works

1. Enter an amount
2. Application figures out how to hand out your amount in available banknotes from a specified depot
3. The depot (depot.csv, depot.json) holds information about how many banknotes are available
4. Application writes back the availability for every hand out banknote

PS: don´t judge me about my naive json implementation :D - I wanted to do without external dependencies...
