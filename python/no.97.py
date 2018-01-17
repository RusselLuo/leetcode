class Solution(object):
    def isInterleaveHelper(self, s1, s2, s3,legal):
        """
        :type s1: str
        :type s2: str
        :type s3: str
        :rtype: bool
        """
        if len(s3)!=len(s2)+len(s1):
            return False
        if len(s3)==0:
            return True
        curr = s3[0]
        if len(s1)==0 and len(s2)==0:
            return True
        if not legal[len(s1)][len(s2)]:
            return False
        legalS1 = False
        legalS2 = False
        if(len(s1)!=0 and s1[0]==curr):
            legalS1 = self.isInterleaveHelper(s1[1:],s2,s3[1:],legal)
        if(len(s2)!=0 and s2[0]==curr and not legalS1):
            legalS2 = self.isInterleaveHelper(s1,s2[1:],s3[1:],legal)
        legal[len(s1)][len(s2)]=legalS1 or legalS2
        return legalS1 or legalS2
    def isInterleave(self,s1,s2,s3):
        legal = [[True for b in range(len(s2)+1)] for bb in range(len(s1)+1)]
        return self.isInterleaveHelper(s1,s2,s3,legal)