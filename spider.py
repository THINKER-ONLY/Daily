from bs4 import BeautifulSoup
import urllib.request
import re
import xlwt

def main():
    baseurl = "https://movie.douban.com/top250?start="  # 修正了URL
    savepath = ".\\豆瓣top250.xls"
    datalist = getData(baseurl)
    saveData(datalist,savepath)

findlink = re.compile(r'<a href="(.*?)">')
findimg = re.compile(r'<img.*src="(.*?)" ', re.S)
findname = re.compile(r'<span class="title">(.*)</span>')
findrank = re.compile(r'<span class="rating_num" property="v:average">(.*)</span>')
findjudge = re.compile(r'<span>(\d*)人评价</span>')
findsum = re.compile(r'<span class="inq">(.*)</span>')
findbd = re.compile(r'<p class="">(.*?)</p>', re.S)

def getData(baseurl):
    datalist = []
    for i in range(0, 10):  # 这里应该是0到9，因为start参数是从0开始的
        url = baseurl + str(i * 25)
        html = askURL(url)
        soup = BeautifulSoup(html, "html.parser")
        for item in soup.find_all('div', class_='item'):  # 应该指定查找的HTML元素
            data = []
            item = str(item)
            link = re.findall(findlink, item)
            if link:
                data.append(link[0])  # 如果找到了链接，添加到data列表
            else:
                data.append('')  # 如果没有找到链接，添加空字符串
            img = re.findall(findimg, item)
            if img:
                data.append(img[0])  # 如果找到了图片链接，添加到data列表
            else:
                data.append('')  # 如果没有找到图片链接，添加空字符串
            name = re.findall(findname, item)
            if len(name) == 2:
                cname = name[0]
                data.append(cname)
                ename = name[1].replace("/"," ")
                data.append(ename)
            else:
                data.append(name[0] if name else '')
                data.append(' ')
            rating = re.findall(findrank, item)
            if rating:
                data.append(rating[0])  # 如果找到了评分，添加到data列表
            else:
                data.append('')  # 如果没有找到评分，添加空字符串
            judge = re.findall(findjudge, item)
            if judge:
                data.append(judge[0])  # 如果找到了评价人数，添加到data列表
            else:
                data.append('')  # 如果没有找到评价人数，添加空字符串
            summarize = re.findall(findsum, item)
            if summarize:
                summarize = summarize[0].replace("。", "")
                data.append(summarize)
            else:
                data.append(" ")
            bd_list = re.findall(findbd, item)
            if bd_list:
                bd = bd_list[0]  # 确保bd是一个字符串
                bd = re.sub('<br(\s+)?/>(\s+)?', " ", bd)
                bd = re.sub('/', " ", bd)
                data.append(bd.strip())
            else:
                data.append('')  # 如果没有找到简介，添加空字符串
            datalist.append(data)
    return datalist

def askURL(url):
    head = {
        "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/130.0.0.0 Safari/537.36 Edg/130.0.0.0"
    }
    request = urllib.request.Request(url, headers=head)
    html = ""
    try:
        response = urllib.request.urlopen(request)
        html = response.read().decode("utf-8")
    except urllib.error.URLError as e:
        if hasattr(e, "code"):
            print(e.code)
        if hasattr(e, "reason"):
            print(e.reason)
    return html

def saveData(datalist,savepath):
    work = xlwt.Workbook(encoding="utf-8")
    sheet = work.add_sheet('豆瓣电影top250',cell_overwrite_ok=True)
    col = ("电影详情链接","图片链接","电影中文名","电影英文名","评分","评价人数","概况","相关信息")
    for i in range(0,8) :
        sheet.write(0,i,col[i])
    for i in range(0,250) :
        data = datalist[i]
        for j in range(0,8) :
            sheet.write(i+1,j,data[j])
    work.save(savepath)

if __name__ == "__main__":
    main()
    print("爬取完毕")