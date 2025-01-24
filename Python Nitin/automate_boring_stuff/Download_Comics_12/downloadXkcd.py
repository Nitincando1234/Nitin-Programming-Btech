# downloadXkcd.py - Downloads every single XKCD comic. 
import requests, os, bs4
url = "https://xkcd.com" # starting url
os.makedirs("xkcd", exist_ok = True)
try:
    while not url.endswith("#"):
        # Download the page.
        print("Downloading page %s..." % url)
        res = requests.get(url)
        res.raise_for_status()
        soup = bs4.BeautifulSoup(res.text, "html.parser")
        comicImgElem = soup.select("#comic img")
        if comicImgElem == []:
            print("Could not find the comic's image.")
        else:
            comicImgUrl = "https:" + comicImgElem[0].get("src")
            print("Downloading the image %s..." % (comicImgUrl))
            res = requests.get(comicImgUrl)
            res.raise_for_status()
            comicImgFile = open(os.path.join("xkcd", os.path.basename(comicImgUrl)), "wb")
            for chunk in res.iter_content(100000):
                comicImgFile.write(chunk)
            comicImgFile.close()
        prevLink = soup.select('a[rel = "prev"]')[0]
        url = "https://xkcd.com" + prevLink.get("href")
except KeyboardInterrupt:
    print("You have cancelled the download. ")
print("done. ")