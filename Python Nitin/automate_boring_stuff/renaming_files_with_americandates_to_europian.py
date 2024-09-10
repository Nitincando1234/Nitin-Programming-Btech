import re, os
datePattern = re.compile(r"""^(.*)? 
        ((0|1)?\d)-                  # month
        ((0|1|2|3)?\d)-              # day
        ((19|20)\d\d)               # year
        (.*)?$""")
