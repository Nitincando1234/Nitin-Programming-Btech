# xkcdComicsMTdownloader.py - Downloads XKCD comics using multiple threads.
import threading, os, bs4, requests
os.makedirs("xkcd", exist_ok = True)

def downloadXkcd(startComic, endComic):
    try:    
        for urlNumber in range(startComic, endComic):
            print("Downloading page https://xkcd.com/%s..." % urlNumber)
            res = requests.get("https://xkcd.com/%s" % urlNumber)
            res.raise_for_status()
            soup = bs4.BeautifulSoup(res.text, "html.parser")
            comicElem = soup.select("#comic img")
            if comicElem == []: print("Could not find the image !")
            else:
                comicUrl = comicElem[0].get("src")
                print("Downloading image %s..." % comicUrl)
                res = requests.get("https:" + comicUrl)
                res.raise_for_status()
                imageFile = open(os.path.join("xkcd", os.path.basename(comicUrl)), "wb")  
                for chunk in res.iter_content(100000):
                    imageFile.write(chunk)
                imageFile.close()
    except KeyboardInterrupt: print("Interupted !")

# Start the download threads
allThreads = []
for i in range(0, 3400, 10):
    start = i
    end = i + 9
    if start == 0: start = 1
    thread = threading.Thread(target = downloadXkcd, args = (start, end))
    allThreads.append(thread)
    thread.start()

try: 
    for downloadThread in allThreads: downloadThread.join()
except KeyboardInterrupt: print("Interrupted !")
print("\nDone.")