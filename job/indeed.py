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

'''
<div id="searchCount">招聘信息1 - 10共2,752条</div>
<div id="searchCount">Jobs 1 to 10 of 2,755</div>
'''

class Indeed:
    def __init__(self):
        #self.skills = ["java","c++","c#","python","scala","f#","nosql","aws","azure",""]
        self.skills = []
        self.pattern = '[\d\D]*of[\s]?(\d*)$'
        self.confFile = "skills.txt"
        return

    def parseContent(self):
        return
     
    def readConf(self):
        fp = open(self.confFile, 'r', -1)
        for line in fp:
            line = line.lstrip()
            line = line.replace("\n","")
            line = line.replace(" ","+")
            print line
            if line:
                if (line[0] == "#"):
                    print "skip",line
                    continue
                self.skills.append(line)        
        print self.skills
        fp.close()
 
    def drawChart(self, dict):

        #In [2]: 
        dict = {'A': 40, 'B': 70, 'C': 30, 'D': 85, 'E':10,'F':34,'G':33}
        fig = plt.figure()
        ax = fig.add_subplot(1, 1, 1)
        max_yticks = 3
        ax.yaxis.set_major_locator(mticker.MaxNLocator(max_yticks))
        for i, key in enumerate(dict): 
            #plt.bar(i, dict[key])
            #plt.xticks(np.arange(len(dict))+0.4, dict.keys(), rotation='vertical')
            #plt.yticks(dict.values());
            #rects1 = ax.bar(ind, menMeans, width, color='r', yerr=menStd)
            ax.bar(i, dict[key])
         
        ax.set_xticks(np.arange(len(dict))+0.4)   
        ax.set_xticklabels(dict.keys(), rotation='vertical')
        ax.set_yticklabels(dict.values());
        plt.show()
        return
                        
    def process(self):
        m = {}
        self.drawChart(m)
        return
        country = "Singapore"
        self.readConf()
        
        for key in self.skills:
            url = "http://www.indeed.com.sg/jobs?q=" + key + "&l=" + country
            print "checking",url    
            try:  
      
                page = urllib2.urlopen(url).read()
            except:
                print " Data Not found"
                continue
            soup = BeautifulSoup(page)
            div = soup.find("div",id='searchCount')
            if div!=None:
                #replace , with space
                line = re.sub(',','', div.string)
                an = re.match(self.pattern, line)
                if an!=None:
                    m[key] = int(an.group(1))
        
        print m 
        self.drawChart(m)           
        print "Done,exit..."       
################################################################################        
# main routine
################################################################################            
if __name__ == "__main__":
    obj = Indeed()
    obj.process()
        