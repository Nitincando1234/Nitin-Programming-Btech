import requests, sys, webbrowser, bs4, time, os
query = " ".join(sys.argv[1:])
try:
    print(f"Searching for {query}...")
    res = requests.get(f"https://pypi.org/search/?q={query}")
    res.raise_for_status()
    soup = bs4.BeautifulSoup(res.text, "html.parser")
    linkElems = soup.select(".package-snippet")
    numOpen = min(5, len(linkElems))
    for i in range(numOpen):
        urlToOpen = "https://pypi.org" + linkElems[i].get("href")
        print("Opening", urlToOpen)
        browser = webbrowser.get("C:\\Program Files\\Google\\Chrome\\Application\\chrome.exe")
        browser.open(urlToOpen)
except Exception as e:
    print("An error occurred:", e)
# time.sleep(5000)
print("Done.")