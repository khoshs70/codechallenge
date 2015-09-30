# -*- coding: utf-8 -*-
'''
analysis technique skill demand on jobs website
'''

from bs4 import BeautifulSoup
import urllib2
import re
import matplotlib.pyplot as plt
import numpy as np
import matplotlib.ticker as mticker
from matplotlib.backends.backend_pdf import PdfPages
import csv

'''
<div id="searchCount">Jobs 1 to 10 of 2,755</div>
'''

class Indeed:
    def __init__(self):
        #self.skills = ["java","c++","c#","python","scala","f#","nosql","aws","azure",""]
        self.skills = {}
        self.catResult = {}
        self.pattern = '[\d\D]*of[\s]?(\d*)$'
        self.confFile = "skills_matrix.txt"
        self.country = "Singapore"

        return

    def makeReport(self):
        return
     
    def readConf(self):
        fp = open(self.confFile, 'r', -1)        
        reader = csv.reader(fp)  # creates the reader object
        idx = 0
        for row in reader:
            if idx==0:
                idx += 1
                continue
            caty = ""
            for rowid, item in enumerate(row): 
                item = item.replace(" ","+")           
                if (rowid==0):
                    lst = {}
                    if (item[0]=="#"):
                        print "not interested",item
                        break
                    self.skills[item] = lst
                    print item,rowid
                    caty = item
                else:
                    lst = self.skills[caty]
                    lst[item] = 0
                    
            idx += 1
        fp.close()      
        print self.skills

    def autolabel(self,ax, x, key, height, width):
#        height = rect.get_height()
        ax.text(x+width/2, 1.05*height, '%s\n%d'%(key,int(height)),
                ha='center', va='bottom')
                    
    def drawChart(self, dict, t):
        #dict = {'A': 40, 'B': 70, 'C': 30, 'D': 85, 'E':10,'F':34,'G':33}
        fig = plt.figure()
        ax = fig.add_subplot(1, 1, 1)
        max_yticks = 3
        ax.yaxis.set_major_locator(mticker.MaxNLocator(max_yticks))
        colors = "bgrcmykw"
        color_index = 0
        for i, key in enumerate(dict): 
            ax.bar(i, dict[key],color=colors[color_index], width=0.4)
            color_index += 1
            if (color_index==len(colors)):
                color_index = 0
            self.autolabel(ax,i,key,dict[key],0.4)
         
        ax.set_xticks(np.arange(len(dict))+0.4)   
        ax.set_xticklabels(dict.keys(),rotation=45)
#        ax.set_xticklabels(dict.keys(), rotation='vertical')
        #ax.set_yticklabels(dict.values());
        plt.title(t)
        plt.show()
        return fig
    
    def parseHtml(self,url,m,key):   
        try:          
            page = urllib2.urlopen(url).read()
        except:
            print url,"Data Not found"
            return                
        soup = BeautifulSoup(page)
        div = soup.find("div",id='searchCount')
        if div!=None:
            #replace , with space
            line = re.sub(',','', div.string)
            an = re.match(self.pattern, line)
            if an!=None:
                m[key] = int(an.group(1))
        return
 
    def analysis(self):
        # open pdf
        with PdfPages('skills_report.pdf') as pdf:
            for category in self.skills.iterkeys():            
                url = "http://www.indeed.com.sg/jobs?q=" + category + "&l=" + self.country            
                #print "checking",url 
                self.parseHtml(url, self.catResult, category)
                lst = self.skills[category]
                for key in lst.iterkeys():
                    url = "http://www.indeed.com.sg/jobs?q=" + key + "&l=" + self.country
                    #print "checking",url
                    self.parseHtml(url, lst, key)
                fig = self.drawChart(lst,category)                
                pdf.savefig(fig)  # saves the current figure into a pdf page
                #plt.close()

            fig = self.drawChart(self.catResult,"overall")
            pdf.savefig(fig)  # saves the current figure into a pdf page
            #pdf.savefig()
            plt.close()
        return
                                                
    def process(self):
        #m = {}
        #self.drawChart(m)
        #return
        self.readConf()
        self.analysis()
        #self.drawChart(self.catResult)
        print "Done,exit..."       
################################################################################        
# main routine
################################################################################            
if __name__ == "__main__":
    obj = Indeed()
    obj.process()
        