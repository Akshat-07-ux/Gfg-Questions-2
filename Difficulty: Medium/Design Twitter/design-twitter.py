from collections import defaultdict
import heapq

class Twitter:
    def __init__(self):
        self.timestamp = 0
        self.tweets = defaultdict(list)
        self.following = defaultdict(set)
        
    # Compose a new tweet
    def postTweet(self, userId: int, tweetId: int):
        self.tweets[userId].append((self.timestamp, tweetId))
        self.timestamp += 1
        
        
    # Retrieve the 10 most recent tweet ids
    def getNewsFeed(self, userId: int):
        max_heap = []
        
        if self.tweets[userId]:
            for t in self.tweets[userId]:
                max_heap.append(t)
                
        for followeeId in self.following[userId]:
            if followeeId in self.tweets:
                for t in self.tweets[followeeId]:
                    max_heap.append(t)
                    
        max_heap.sort(key = lambda x: x[0], reverse=True)
        return [tweetId for _, tweetId in max_heap[:10]]

    # Follower follows a followee.
    def follow(self, followerId: int, followeeId: int):
        # Code Here
        if followerId != followeeId:
            self.following[followerId].add(followeeId)

    # Follower unfollows a followee.
    def unfollow(self, followerId: int, followeeId: int):
        # Code Here
        if followeeId in self.following[followerId]:
            self.following[followerId].remove(followeeId)