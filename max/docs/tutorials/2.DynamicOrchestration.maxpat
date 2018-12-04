{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 7,
			"minor" : 3,
			"revision" : 4,
			"architecture" : "x64",
			"modernui" : 1
		}
,
		"rect" : [ 59.0, 79.0, 930.0, 768.0 ],
		"bglocked" : 0,
		"openinpresentation" : 0,
		"default_fontsize" : 13.0,
		"default_fontface" : 0,
		"default_fontname" : "Arial",
		"gridonopen" : 1,
		"gridsize" : [ 15.0, 15.0 ],
		"gridsnaponopen" : 1,
		"objectsnaponopen" : 1,
		"statusbarvisible" : 2,
		"toolbarvisible" : 1,
		"lefttoolbarpinned" : 0,
		"toptoolbarpinned" : 0,
		"righttoolbarpinned" : 0,
		"bottomtoolbarpinned" : 0,
		"toolbars_unpinned_last_save" : 0,
		"tallnewobj" : 0,
		"boxanimatetime" : 200,
		"enablehscroll" : 1,
		"enablevscroll" : 1,
		"devicewidth" : 0.0,
		"description" : "",
		"digest" : "",
		"tags" : "",
		"style" : "",
		"subpatcher_template" : "",
		"boxes" : [ 			{
				"box" : 				{
					"id" : "obj-10",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 15.0, 1694.995239, 889.599976, 21.0 ],
					"style" : "",
					"text" : " "
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-17",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 500.000031, 1193.0, 109.0, 23.0 ],
					"style" : "",
					"text" : "exportsolutions 0"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-16",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 401.000031, 1172.0, 81.0, 23.0 ],
					"style" : "",
					"text" : "popsize 100"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-14",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 281.0, 1151.0, 102.0, 23.0 ],
					"style" : "",
					"text" : "maxepochs 100"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-9",
					"maxclass" : "newobj",
					"numinlets" : 3,
					"numoutlets" : 2,
					"outlettype" : [ "", "" ],
					"patching_rect" : [ 68.0, 1177.0, 94.0, 23.0 ],
					"style" : "",
					"text" : "orchidea.solve"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-8",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 11.0, 1064.995239, 889.599976, 36.0 ],
					"style" : "",
					"text" : "In order to speed up the search for dynamic orchestrations, we suggest to reduce the number of epochs and the population size to 100. Moreover, it is a good practice to reduce the number of solutions stored (or even to avoid storing them altogether and just save the final connection."
				}

			}
, 			{
				"box" : 				{
					"hidden" : 1,
					"id" : "obj-11",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 668.099976, 1663.384766, 203.0, 23.0 ],
					"style" : "",
					"text" : "load 3.BrowsingSolutions.maxpat"
				}

			}
, 			{
				"box" : 				{
					"hidden" : 1,
					"id" : "obj-39",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 668.099976, 1690.384766, 57.0, 23.0 ],
					"style" : "",
					"text" : "pcontrol"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-13",
					"maxclass" : "textbutton",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "", "", "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 668.099976, 1638.0, 232.5, 19.999907 ],
					"style" : "",
					"text" : "Browsing solutions"
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"bubbleside" : 2,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-12",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 668.099976, 1579.0, 232.5, 55.0 ],
					"style" : "",
					"text" : "Tip: follow the next tutorial to learn how to browse solutions!"
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"bubbleside" : 0,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-3",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 401.000031, 893.900146, 136.499969, 55.0 ],
					"style" : "",
					"text" : "Check the dynamic solution in text format"
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-1",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 375.799957, 623.299988, 182.0, 25.0 ],
					"style" : "",
					"text" : "Run dynamic orchestration"
				}

			}
, 			{
				"box" : 				{
					"autofit" : 1,
					"data" : [ 43492, "png", "IBkSG0fBZn....PCIgDQRA..G3D..LfsHX....va3R6c....DLmPIQEBHf.B7g.YHB..f.PRDEDU3wI6cmGmUUee+3+8rw91.JJ66atQTAUvMPE2WvkZRLZpKgnXZSZa9llGVZZsIMwp0Fqs9yknwnwUL3NJBhD.QAQEDD2U.U.YQ1GVFlYX98GDlxvvvhL26Yl4774e4ctm64yq6cl60OLulOeN4Td4kWd.........PJVtIc..........Hoo3T........fTOEmB........j5o3T........fTOEmB........j5o3T........fTOEmB........j5o3T........fTOEmB........j5o3T........fTOEmB........j5o3T........fTOEmB........j5o3T........fTOEmB........j5o3T........fTOEmB........j5o3T........fTOEmB........j5o3T........fTOEmB........j5o3T........fTOEmB........j5o3T........fTOEmB........j5o3T........fTOEmB........j5keRGfZqV3m+4wbl6bq31GvAb.wwOnAkfIB........HSQwoUiUs5UGu668dUb6tz4Nq3T........ndJaUu.........odJNE........H0yV0aJzaMqYEqccqqhae7G2wEMpQMJASD0FUd4kGSZJSoha2nF1PaW0.......P8VJNME5cm27hEujkTwsGvQcTJNkcooOiYTw+cKZQKTbJ.......TukspW........fTOEmB........j5o3T........fTOWiSyB15V2ZrxUtxXUqd0Qt4labvG7AGMuYM6a74qrxJKVyZWarl0rlXiaZSQSaZSiBaUqhBaUqpAS89l0WTQwW+0ecrgMrgn4Mu4QW5bmSrrryJu7xiu9q+5X0qYMQokVZzhVzh3fZaaiBJnfp8wTVYkEqXEqHVyZWajWd4se+8rc1F1vFhktrkEkUVYQaOvCLZYKaYjSN4Tic9iHh0st0EqbUqJ1zl1TbfG3AFGPaZSM9Xrmr0st0XsqacwZVyZhh1vFhF23FGspEsHNfC3.xp4........XOQwo0.du2+8ioNsoUwsOigMrn6cqaQYkUVLy25sh27se6XcqacU5wzrl1znO8t2wocJmxts.ucz5V+5iY9VuULqYO6XKaYKU49acqacbXGxgDG2wbLQCZPCp3qO0oMs38d+2uhau1cJKO7i9nQt4V4Ee7PNoSJ5We6aE29klvDhErvEVwsGwUe0Q94mer50rlXRSdxwG7geXE2WyadyiexO5GUwsesoO8Xtu66VwsOkgLjnO8t26wmui4oe5XEqXEUb6K6a+siV1xVVkiaUqZUwnGyXp31Gwge3wwOnAEQDwrem2Id823MhUu5UWoGSCaXCi9eDGQLzS5jpzq+EWbwwqOiYDuyblSrgMtwJ8X9l78rczm9YeV7lu8aGKaYKKJZCanR2WCZPChCpssMF3Qezwgzu9sGOWEWbww8+fOXE2tGcu6woeZmVDQDyeAKHdsoO83y+hunROl7yO+nCsu8wYc5md0Vb4S7jOYrxUtxc48s90u93t9c+tp70+NW5kVkR62zl1T7VyZVwa81ucUdcLhHZQKZQzu91233OtiKZRSZxt+IK.......PVfhSqAr0xKOV4pVUE2dsqcswF1vFhw7zOc7kKZQ6xGSQaXCwaO6YGewhVTbICe3QaZSa1siwm+EeQ7nidzQYkUV0dLqZUqJl5zlVL624chK37NunqcoKQDaa0Mti4ams50rlp7017l2bkucwEWoywF2zlh7xM23QdrGKVyZWakN1FrSkJVzNM9EWbwUaV1QqcsqsROtx15V2kGWt4kWkNtUtxUFkVZowy+huXkJLdGUbwEGy7Mey3K+xuL9NW5kFMsIMI95Utx3O8jOY09Z0952y1tMs4MGu7DmXL24Mup8X1xV1R7kKZQwWtnEEe3G8QwYcFmQz3F23p83KnfBpTNadyadTd4kGScZSKd0W601kOlRKsz3y+huH98O3CFm0YbFwQbXGVUNl0rl0TsO+Kem947sam+Yxu9q+53Ad3GtJ+LzNZcqacwaLyYFyYtyMNqy3LhCcunrX.......fLIWiSqAzvcX0cFQDEuksD+om5opToo4jSN6xsI0UrhUDO5nGcTZokVsm+ku7kGOwS9jUpfpBJnfncG7AGs6fO3pbdWeQEEidLiIVxW8UeSeJUE67ywMtwMFidLioJklFQDErSGal1NmssTRIwqL4IWoRSqtW++pktz3km3DiMu4MGO1nGcUJFbmWItQrsum8H6gumscKdIKItm68dqRoo4latQaaaai1cvGbje9U9ueg2+C+v3tuu6KVytnP6c7wuiOtRJoj3Me62tJkllWd4UkGaIkTR7bicrwB+7OeOl+8Uqa8qOdzm3IpToo4kWdwAePGTzg129p754l27lim44dt3S9zOsFOK........6KrhSqAj6NUN0Leq2phsl2Cse8KFvQezwAePGTTd4kGKdIKIdqYMq3i93OthiesqacwaO6YGG6.G3t77+ZyXFUZUZdBCdvwfOtiqhsi2hKt33K9xuLlvq7JUrkz1wNzgn0EVXDQDG9gcXQ6ZW69+Neu9qWoUY5oNzgVkU2Xm5XG2sOGe1wN1J1Fca2AevQ26V2h12t1E4me9Q4kWd08RUFwNWN3hW7hi0WTQQDQz0tzk3DO9iOZ+e44+RW1xhW4O+miEs3EWwwOu2+8iUul0TwVXbm6TmhiY.CH5bm6bTP94GK4q9p3Mdy2L93O4Sp3wrt8v2yhXaET9LO2yUosk2BKrv3LNsSK5VW6ZE4dqacqwhV7hiWXbiqhha2vF1P7xSZRwe0EcQ61m2au71Uu5UGSZxSthw3zF5PiNz91GMsoMMV9JVQ7Yye9wedJSoReu4OOkoDW02+6Woy4IehmXro+RomkWd4wKLtwUw80nF0n3zNkSoJ4nYMsoU7e+1yZVUZao9acDGQbJCcnQS9K+7UIkTRrnEu3XxScpwhWxRhHhnsG3AFGTaaa097D.......HaPwo0.14UQ21KNZXmxoDG6wbLU595VW6ZzkN243Ye9mOduO3Cp3qOsW+0iAdzG8tbENtiqb0t1ktDC4jNoJc+MrgML5UO6Yzt10t3Qd7GO5TG5Pblm9oWw4picnCQG6PGp33m867NUp3zCoe8KZYKZw9zywsWZ5fNtiKNkS9j2kqlyrkcNaauzzuU+6eb1mwYTo6uScriwUbYWV7vO1iUoWW2dId8pm8Lt3gO7JsZN6Rm6bzoN1w3IelmoREdu69dVDQLkoMsJ85b+5aeiK3bO2prBSyM2biN2oNE+fq5phG+O8mp3ZS5G8webL+Etvn6csq65m26vq4abSaJhXa+70EO7gGMpQMph66fZaaiCpssMZcgEFi4oe5J8b9yVvBhdzstUwWaGu1ytyEm1fFzf3acDGwtLKa2N9ZZgspUw4d1mckt+BJnfnacsqQGZe6im3IexnfBJHtvy+7qz0jW.......fjfsp2Z.6pJC6dW6ZUJMc6xM2biSYnCsResMsoMUwJdbGUTQEUoUv21WEo6JMqoMMt5u+2ON6y7Lq1x79lZW8bbfG8QGm5PFRhVZZ0oYMqYwYNrgsKecHu7xKF7wcbU4q2fFzfX3m24UkhMiXaeO6T2K+dVDaaK.9Ml4Lq31so0sNNuy9r2km6sqfBJHNyS+zqzqmu7q7JU6wG6zq64me9w4cNmSkJMcG029zmprRh+pZvsy4xKu7Js8PW3t4mUaPCZP7c9q9qhK8huXklB.......0Jn3zLjgNjgrau+V1hVTkRrV0eYa1cG0jlzjJU11m9YeVEqnxckBJnf8sf9MT94meb7CZPYkw5ahiePCZ2VRYO5d2qxWq+G9gGMrgMrZeLstvBqXK+c61UeOKhHdu2+8qz1h6PO4SdupfvC7.Nfn66vJ.cEqXEU55E5ty.N5iNZQya9t8XNj90uJc6UWM4+ahbxImn46v3unEu33qW4Jq1iO+7yuVYo6.......P5jhSy.ZXCaXztC9f2iGWqacqqzsWyNrsttc4latUprt0s90G+9+veHl1NccJMaqGcu6QyZVyRrweOoqcoK616O2byMZRSZRk9Z6XgkUmCnMsoR2dW88rHhX4Ke4U7emSN4DcqZ1tc2U14q2m6txG2Q6omyQrsU95Npl9mg5zNrkPuksrk3O7G+iwqL4IWwV6L.......PsUtFmlATXqZ0d0wsyE2UZoktKOtgbRmT7HO9iGkUVYQDQTzF1PL4oN0XxScpQqZUqhdzstE8tW8J5Rm67tcUVVSZ2skAWaPqZYK2iGSiZTihMtwMVwsawd357ZDQzzl1zJc6RKojc4wsrcn3z7yO+34dgWXOdt2tctL1UtpUUoqQsUmVuW7yc6s+L22TG+fFT7we5mVwpjs3hKNl9LlQL8YLinYMqYQO5V2hd0ydFcuacyVzK.......TqhhSy.Z4dQocQDQA6kkb14N0oX3m24EuvK8RUYaacMqYMwaO6YGu8rmczvF1vXPG6wFG6.GXFeK6cu84XRnIMtweid9uykhtqr2T1WQaXCwF1gBYKojRhO5i+3847rcqbubEmt278jL8OWzl1zl3Ru3KNd5m64h0u90Wo6qnhJJly69twbd22MxKu7hAdzGcb7CdvQiqlqIq........YS1pdy.xDW2F6We6a72bcWWbRmvITksK1sq3hKNl7TmZbW268FqcsqsFOC6n7xKuL54OhHJeOeH6R4j62rerdu46Z630szpSIUypP8ap81qwo0Vtdg14N0o3GcsWaLrS8TiCtZ1xpKqrxhYLyYF++c22crzktzrbBA.......pJq3z5PZTiZTbRmvIDmzIbBwpWyZh4ufEDyeAKH9r4O+Jskqtt0st3wGyXhq5JthZkaGpk9W1xg2S14UrXcEspksLZPCZPrksrkHhs88sK4Buvuwmu8lsP3ZaxO+7iicfCLN1ANvX8EUTL+ErfXAKXAwm7YeVTbwEWwws4Mu4XziYLwUekWYz7ZwWybA......f5+TbZcTE1pVEG8QdjwQejGYr4Mu43Me62Nlxq9pUb+qXEqH9z4O+3P5aeSvTtM4sSq.zc75JZ0ojRJI1vF1PlJRYT4jSNwA011Fe4hVTDw1JGr0EVXcxBPqIz7l0rn+G9gG8+vO7njRJIly69twK+JuREWydWeQEEyadyKFzwcbIbRA......fzLaUu0CznF0n3DO9iONoS3DpzWeQKdw6cmf8hse18G670dy8lsQ3EujkjohSVwA011Voa+YKXAITRpAUC7yIETPAw.NpiJNmy7LqzWeQ0w+9M.......T2mhSqiXYKe46wioScriU51aYG1RT2QMbm19d23l1z27fsWnvBKrR29i9jOI15V25t8wL0oMsLYjx35Q26dkt8jl7j2q25gWvBWX7tyadYhXsOImbxIxO++uEk9d6OmrhUrh832e6Tm5TktcwUyOqB.......jsn3z5.d8YLi3du+6OF23GeT9tYU+srksrJc6Nz91uKOtctHyL8p67.aSapzs23F2XL64Lmp83m8blS7Ee4WlQyTlVu5YOi91m9Tws2zl1T7TO6yFaXOrME+gezGEO9e5OEO6XGaLgINw8XAjYZ63OqTZokFKeOTf+bm27h68O7Ghw7zOcTRIkTsG2RW5RqzsqteVE.......HaQwo0hUVYkEO+K9hwjl7jiHh3sm8rim3Iex3y+huHJszRqzw9Ie5mFSYmVklcbmVApa2NWb5qNsoEyXlyLJpnhhxKu7XoKcoQQ0fWeQaYKaYzuc5Zs53F+3i2XlyrRqhwhJpnX7SbhwKLtwEQrss00cTRWh39py5zO8nwMpQUb6ubQKJt6e2uKdm4LmprBKW25We7mmxThm7YdlJt1eNy25shIO0olUy7Nq06zOq7ricrw6Nu4EaYKaIJqrxh4uvEFQDQ4kWdL4oN034F6Xist0sFe7m7Iwi73Od7oye9wV1xVpz4XwKYIw3e4WtRescd0RC.......jsk+d9PHojSN4TkRm9jO8SiO4S+zH+7yO5XG5Pje94Ge8JWYrl0rlJcb8sO8INfcZkdtcG9gdnwTm1zp3bugMtwXhSZRwq7m+yQDaqDru2246DMqoMsF64xPNwSL9vO5ipzJl8kmzjhWdRSJJrvBiRKszJsU11tC9fiNz91Gu0rlUEess9WJTrthl1zlFm8YdlwS+bOWEk9toMu4XriabwXG23hV0pVEMuYMKVeQEEqcsqsJql312t1EmvfGbRD8JLfi5nhO5i+3Jt8xV9ximcriMxM2bq34zM7y9YQd4kWrkcZEltnEu33wehmHxM2biNz91GMtwMNV0pVU70qbkU535XG5Pz0tzkL+SF.......fcCq3zZwxM2biK77O+X.G0QUk6qzRKMV3m+4wm9YeVUJMsycpSwvOuyKxImb1km2l1zlFC4jNop70Ku7xqn7tcdEst+pMsoMw4bVmUjWd4Uk6a0qd0UpzzC7.Ov3huvKLZvNcsXcmKlqtf9029Fi3ptpc4VQ6ZVyZhubQKJVyZVSUJM8P5W+hK6a+sqxqAYacqqcsJqV3Hp7p+c6aIum9odpwIehmXjat4Vki8KWzhhO9S9jpTZZaZSahu8kbIU5ZoJ.......PRPaE0xkat4Fm4oe5wQ1+9GSYZSK9r4O+J1JW2YE1pVEGy.FPz+i3H1iEQcLCX.QqKrvXbie7wZW25pz8kWd4UkxupI7sNhiHZ2AcPwS8bOWrxcp.sH11Vy6Q1+9GC4jNonAMnAQiabiqz8uyaus0UbfG3AFW4UbEwaMqYEuwa9lUon6sKmbxI5Rm6bbbG6wF8r6cOKmxp2EcAWPLy129XJ6vpTd6ZXCaXkJQ8DO9iONrC8Pio9puZ7QexmTkie6ZVyZVLfi5nhi9HOxp78Y.......fjPNkuyK0MpUqjRJI97u3Kh0r10FEUTQQCZPChVzhVDspksL5P6ae0tJS2cVeQEEqbkqLJojRhl1zlFs8.OvL9J.b8qe8wxV9xiks7kG4latQgspUQW6RWhFsCWSPqup3hKNV9JVQr7UrhX8qe8QSaZSil2rlEctScJZRSZRRGupU4kWdr50rlXUqZUQN4laz7l0r3.OfCnZ+YtxJqr3K9xuLV0pWcTTQEE4kWdQKaQKhVzhVDcrCcXWt5iA.......RJJNE........H0y03T........fTOEmB........j5o3T........fTOEmB........j5o3T........fTOEmB........j5o3T........fTOEmB........j5o3T........fTOEmB........j5o3T........fTOEmB........j5o3T........fTOEmB........j5o3T........fTOEmB........j5o3T........fTOEmB........j5o3T........fTOEmB........j5o3T........fTOEmB........j5o3T........fTOEmB........j5o3T........fTOEmB........j5o3T........fTOEmB........j5o3T........fTOEmB........j5o3T........fTOEmB........j5o3T........fTOEmB........j5o3T........fTOEmB........j5o3T........fTOEmB........j5o3T........fTOEmB........j5o3T........fTOEmB........j5o3T........fTOEmB........j5o3T........fTOEmB........j5o3T........fTOEmB........j5o3T........fTOEmB........j5o3T........fTOEmB........j5o3T........fTOEmB........j5o3T........fTOEmB........j5o3T........fTOEmB........j5o3T........fTOEmB........j5o3T........fTOEmB........j5o3T........fTOEmB........j5o3T........fTOEmB........j5o3T........fTOEmB........j5o3T........fTOEmB........j5o3T........fTOEmB........j5o3T........fTOEmB........j5o3T........fTOEmB........j5keRG.paorxJKl+7merxUtxnnhJJZbiabTXgEF8nG8HZXCaXRGOfrnUu5UGKbgKLV25VWTVYkEsnEsH5PG5Pzt10tjNZ.YQkUVYwBVvBhu9q+ZyM.R4VyZVSrvEtvXsqcsUL2f1291Gsu8sOoiFPVzV25Vi4O+4Wo4FzpV0pnG8nGQiZTiR53AjEYtA.Qrs4FrfErfXEqXEla.0In3T1idm24chm5odp3kdoWJl6bmaTbwEWkiIu7xK5ae6aLrgMr37O+yOFxPFRjSN4j.oEHSYCaXCwS+zOc7hu3KFSYJSIVxRVxt73ZcqacLnAMn3rO6yNt3K9hiC5fNnrbRAxzlyblSklavl27lqxwjWd4E8oO8oh4FLzgNTyM.pmYiabiwy7LOS7BuvKDSYJSIV7hW7t73JrvBiAMnAEm0YcVwkbIWRbvG7AmkSJPl1bm6bim9oe5Xbiabwblybp14Fz6d26XXCaXw4cdmWbpm5oZtAP8LabiaLd1m8YqXtAKZQKZWdbEVXgwwdrGab1m8YGWxkbI9CvFpGZdyadwS8TOUEyMXSaZSU4XxKu7hd0qdUo4Fjat1jTI4kS4kWd4IcHpu40e8WOhHhAO3AmvIY+yXFyXha8Vu03Mdi2Xe9w1qd0q3m7S9IwO7G9CiBJnfLP5.xVV5RWZbS2zMEOvC7.w5V251mdrMnAMHt3K9hiQMpQEG5gdnYnDBjs7TO0SE25sdqwzm9z2mer8rm8L9w+3ebbsW60FMnAMHCjNfrkksrkE+G+G+Gwe3O7Gh0t10tO8XKnfBhK5htnXTiZTwge3GdFJg.YKO6y9rwsbK2RE+dP1Wzidzi3G+i+ww0ccWm4F.0ws7ku73lu4aNt+6+9i0rl0rO8XKnfBhgO7gGiZTiJ5e+6eFJg.YKO+y+7wsbK2RLsoMs84Ga25V2he7O9GGibjizNXEIJEmlAb5m9oGQDwDlvDR3j7My67NuSLxQNxXFyXF62mqd1ydF29se6wYe1mcMPx.xlJszRia5lto3lu4aN1vF1v904Ju7xKt5q9pia4VtknUspU0PIDHaYtyctwHG4H+F8KEcm08t2831u8aON2y8bqARFP1TokVZbK2xsD2zMcSQQEUz904J2byMtxq7Jia8Vu0nvBKrFJg.YKyadyKF4HG42neon6rt0stE21scawEbAWPMPx.xlJqrxh+y+y+y327a9Mw5W+52uNW4latw2+6+8i+q+q+qn0st00PIDHa48du2Kt9q+5ioN0oteet5RW5Rba21sEW3Edg0.IC12o3zZXSe5SuhUZ5q+5udLnAMnDNQ68Ju7xia4Vtk3e4e4eI1xV1RM5495ttqKtsa61rmkC0Q7IexmDW1kcYwa8VuUM54sScpSwC8POTbxm7IWiddAxbt0a8ViQMpQUiO2fQLhQD29se6QiabiqQOu.YFe1m8YwkcYWVLyYNyZzyaG6XGi+3e7OFCcnCsF87Bj4ba21sE2vMbC6xKiO6Ot5q9pi+2+2+2nIMoI0nmWfLiErfEDeuu226aztQytS6ae6iG7Aev3zNsSqF87Bj47+7+7+D+7e9OeWtU8u+3JuxqLti63Nhl1zlViddg8DEmVC6zO8SOd4W9kiHhXXCaX0YV0oEWbwwUcUWU7XO1ikwFiAMnAEO2y8bwAb.GPFaL.1+8pu5qFCe3COV0pVUF47me94G+te2uKtpq5pxHmefZFaYKaItlq4ZhG9ge3L1XbrG6wFO2y8bQaaaayXiAv9uW60ds3BtfKHV4JWYF47me94G24cdmwHFwHxHmefZFkTRIwHFwHhG7AevL1XLfALfXricrwAcPGTFaL.1+MiYLi37O+yOVwJVQF47mWd4E2wcbGw0ccWWF47CTynzRKMttq65he+u+2mwFii5nNpXricrtVHSVkhSqAsiq1zsqtvpNs3hKNN2y8biINwIlwGqd26dGScpS0+HHnVpW5kdoX3Ce303+0iuqbq25sF+ze5OMiON.661xV1Rb9m+4Gie7iOiOV8rm8Ll5Tmp+QPPsTu7K+xw4e9meM9e836J27Meyw+3+3+XFeb.12URIkDCe3COdwW7Ey3iU26d2ioN0oFcnCcHiOV.66lzjlTbtm64FaZSaJiOV+5e8uN9m9m9mx3iCv9tRKsz3htnKJd9m+4y3iUW6ZWiW8Ue0nicriY7wBhPwo0n1wUa51UaeUmVVYkEWxkbIwy7LOSVaL6e+6eL4IOYWmCgZYdsW60hS+zO8XiabiYsw7du26M9A+fePVa7.1yJqrxhu829aGO4S9jYsw7vNrCKl5TmpqygPsLSe5SOF1vF1980578E28ce2w0dsWaVa7.1y15V2Z7c+te23IdhmHqMlGxgbHwTm5Ti1zl1j0FSf8rYNyYFm5odp62Wqy2WbG2wcD+nezOJqMd.6YkWd4w26688xn6dk6r9129FScpSMNvC7.yZiIoWJNsFxtZ0ltc0lW0o+7e9OOtka4Vx5i6Ye1mcL1wN1HmbxIqO1.U0hVzhhi7HOx3q+5uNqNt4me9wjlzjhS7DOwr53BT8F0nFU7a9M+lr93dFmwYDu3K9hQt4laVerAppkrjkDG4QdjwxW9xypiad4kWLwINwXHCYHY0wEn58u9u9uF+xe4BbRqf...H.jDQAQ0uLqOtm5odpwDlvDL2.nVhktzkFG4QdjwRW5Rypiat4laLgILg3TO0SMqNt.Uue0u5WE+K+K+KY8wcHCYHwDm3Di7xKur9XS5Rd23Mdi2XRGh5Ctlq4Zh4O+4uKuuu3K9h3JthqHKmn8rm+4e93u8u8uMQF6O4S9jngMrgJKApEnzRKMNmy4bhO5i9nr9Xu0st0X7ie7w2+6+8cgdGpEXbiabwHG4HSjw9y9rOKxO+7iS9jO4DY7A9+TVYkEm24cdwG7AePVerKu7xiwO9wGWwUbEQyZVyx5iOPkMgILg3Zu1qMRh+l6WvBVPDQDCcnCMqO1.U1V25Viy+7O+XdyadY8wt7xKOdoW5khK+xu7n4Mu4Y8wGnxdkW4Uhq4ZtlDYtAKbgKLJszR8GRAYbVwo0.1cq1zsq11pNcsqcsQ+5W+hu5q9pDKCETPAwblybh90u9kXY.XaWqQ+Y+reVhlgK6xtr3QdjGIQy.j1s90u9ne8qewhW7hSrLje94Gyd1yNNrC6vRrL.Dw+8+8+c72+2+2mnY3RuzKMF8nGchlAHsqnhJJNjC4Phu7K+xDKC4me9wa8VuUz+92+DKC.aa6xMoV7Ea2EcQWTV8xIBPUswMtw3POzCMV3BWXhkg7xKuXlyblwQcTGUhkAp+y9cRMf8lEsassE16nF0nRzRSiHhRJoj35ttqKQy.j18ke4WVq3ymdzG8QiINwIlzw.R09E+heQhVZZDaaEv6ZaHjrV7hWb7K9E+hjNFwS7DOQ7RuzKkzw.R0twa7FSzRSi3+atA9a9GRNe0W8UwnF0nR5XDO0S8TwK7BuPRGCHU6W9K+kIZooQrscGmq8Zu1XqacqIZNn9Mq3z8S6Mq1zsq1xpNc9ye9Qe5SehRKszjNJQDQL1wN13bNmyIoiAjJMhQLh39tu6KoiQDQDG8Qezwa8VuURGCHU5y+7OO5Uu5UTRIkjzQIhHhm4Ydl3BtfKHoiAjJMxQNx3tu66NoiQDQDequ02Jl0rlUjSN4jzQARcVzhVTzidziXKaYKIcThHh3IexmLtnK5hR5X.oR+s+s+swcbG2QRGiHhHNrC6vh4N24ZtAPBXIKYIQO5QOhMu4MmzQIhHhQO5QGW5kdoIcLndJq3z8S6KqTqZCqpqHh3W+q+00ZJMMhH929292R5H.oRKbgKLdvG7AS5XTg29se6XricrIcLfToeyu42TqozzH11eEq.Yee4W9kw8e+2eRGiJ7Nuy6DO6y9rIcLfToa5ltoZMklFw198F3u6eH6aIKYIw8du2aRGiJLu4MOaWuPB4lu4atVSooQrseuAla.YJJNc+vzm9ziILgIrWe7SXBSHl9zmdFLQ6YqbkqrV20Qv27MeyD+0EHM5ttq6pVUQIQDwse62dRGAH0YMqYMwe7O9GS5XTIyZVyJd0W8US5X.oN28ce20pJJIByM.RBqacqKdfG3AR5XTIyctyMl7jmbRGCH04dtm6IJt3hS5XTIla.j8UTQEUq5OvxHh38du2yk8KxXTb59guIqfzjdUm9POzCUqaBOQD0Z1pPgzhRJojZUq1zs6UdkWIVvBVPRGCHU4ge3GtV0e0nam4F.YWkUVYwe3O7GR5XTESYJSI9zO8SS5X.oJO5i9nwF23FS5XTEla.jcs0st0ZcEkDQDSaZSK9nO5iR5X.oJO9i+3QQEUTRGipvbCHSQwoeCsutZS2tjdUm9XO1ikXi8tyXFyXp0sx2f5ylzjlTrrksrjNFUQ4kWdL5QO5jNFPpRs04F7TO0SUqakuA0mM4IO43q9puJoiQUTd4kGO9i+3IcLfTkZqyM3YdlmoV4erWP8Uu5q9pwhVzhR5XrKUa8yof5qps9dtm64dtZk+wdQceJN8an8mUNZRspSW9xWd7lu4alHi8dx5V25rk7AYQuvK7BIcDpVtNmBYOqbkqLlwLlQRGicohJpHaIePVj4F.DQDqd0qNd8W+0S5XrKswMtwXRSZRIcLfTCyM.HhZ2+d627l2rsqWxHTb52.eSWsoaWRspSm3DmXs5KXx6OulBruo1762lwLlQr90u9jNFPpvq7JuRr0st0jNFUqZyeVETey3G+3S5HTsdy27Mi0rl0jzw.RElzjlTTZoklzwnZYtAP1Ss44FLqYMqXkqbkIcLfTg+7e9OWqdmhzbCHSH+jN.0EUSrhQuwa7Fy5S.YlyblY0waO4yOziqxegwNk3KF6fRlv.oLSH+BiXmeOXsHqdPmdr5jNDPJvwE6h++w0.5x6UyrJVqsM2En9p0u90Ge3G9gIcLpVacqaMJrvBS5X.TKf4F.YGabiaLdu268R5XTsJu7xi27Mey3LOyyLoiBTuWs0cvxsq1d9ntIq3z8Q6uq1zsKIV0ou8a+1Y0wC..1eL6YO6Z06VFP8Euy67N0pW84.rc97JH6XNyYNQYkUVRGicK+dNgriZ6uWaNyYN0p2sLntIEmtOpl75SZ19Zc5m8YeVVc7..f8GEUTQwxV1xR5X.064em.PcEaZSaJVxRVRRGCndu5ByMntPFg5Cps+dshKt3XQKZQIcLndFEmtOnlZ0ltcYyUcZwEWbrzktzrxXA..0T97O+yS5H.06svEtvjNB.rWybCfLu5ByMvmE.YdkWd4wW7EeQRGi8Hed.0zbMNcePm6bm2i6Y1CbfCrR2dOc7sqcsa+NW6MV0pVks5N..pyYkqbkIcDf5879Lf5R7YVPlWcg2mUWHiPccEUTQQwEWbRGi8Hed.0zTb59fNzgNDcnCcXe5wLfALfLTZ12rwMtwjNB..v9rMrgMjzQ.p2y+VAf5RL2.HyqtvbC7YAPlWcgOKHBed.07rU8lRTRIkjzQ...1mYNLPl2V1xVR5H.vdMyM.x7pKL2.eV.j4UW3yBhvmGPMOEmlRz3F23jNB..v9rlzjljzQ.p2y6y.pKwmYAYd0EdeVcgLB00UW48Y0UxI0cn3zThl0rlkzQ...1m0zl1zjNBP8ddeFPcI9LKHyqtv6ypKjQntt5JuOqtRNotCEmlRz5V25nQMpQIcL..f8I6qWe4A1248Y.0k3yrfLu5BuOqtPFg55ZTiZTz5V25jNF6Q97.poo3zThbxImnyctyIcL..f8IcoKcIoi.Tum2mATWhOyBx7pK79r5BYDpOntv60pKjQpaQwooHGxgbHIcD..f8Zctyc1VtCjEbnG5glzQ.f8JcnCcHZYKaYRGCndu5ByMntPFg5Cps+dsC5fNnnMsoMIcLndFEmlhLvANvjNB..vdMycAxN5Se5Sz7l27jNF.rGMfALfjNBPpPO6YOiV0pVkzwX2xmG.YG01euVs87QcS4mzAfrmAO3AmzQ...1qc7G+wmzQ.RExM2bii63Nt3ke4WNoixtTKaYKiUtxUF4kWdIcTf58lwLlQLnAMnjNFUKyM.xNxImbhAMnAEiabiKoixtTyadyiC+vO7jNFPpPs8+eu01yG0MYEmlhbBmvIXKsA.f5LN6y9rS5H.oFmy4bNIcDpVmwYbFJMExRNli4XhC3.NfjNFUKyM.xdpMO2fgMrgEETPAIcLfTgi9nO53fNnCJoiQ0p17mUQcWJNMEI+7yONqy5rR5X...6Q8oO8I5Se5SRGCH037NuyKoiP05BtfKHoi.jZjat4Fm64dtIcL1k5QO5Qs9qyZP8Im64dtQN4jSRGicIyM.xdxImbp09uUnKcoKwQbDGQRGCpGRwooLW0UcUIcD..f8nq7JuxjNBPpR26d2iS9jO4jNFUQKaYKiK7BuvjNFPpRs0euAla.jc0ktzk3TNkSIoiQUz7l273hu3KNoiAjpXtAj1n3zTlS6zNsnqcsqIcL..fpUAETf+APPBXDiXDIcDphK+xu7nwMtwIcLfTkS5jNoZc65C4me90Z+k1B0mUabtAW1kcYQSaZSS5X.oJCdvCNNjC4PR5XTI4kWdwUe0WcRGCpmJmxKu7xS5PTexNuEVTa7k269tu6XjibjIcLpvHG4Hi67NuyjNFPpSIkTRzqd0q3y+7OOoiRDQDMnAMH9jO4ShN24NmzQARctu669pU8KEYDiXDwu6286R5X.oNkVZoQu6cuiErfEjzQIhXaEk7we7GGcqacKoiBj57.OvCTqpnxq5ptp39u+6OoiAj5TVYkE8su8M9zO8SS5nDQrshR9vO7Cid1ydlzQARcd3G9giq3JthjNFU3JthqH9i+w+XRGCpmxJNME5pu5qtVSwDMrgMLtga3FR5X.oRETPAw+z+z+TRGiJTa5ylfzl+5+5+5ZM6HEMnAMHF0nFURGCHUJ+7yO9m+m+mS5XTgq7JuRklBIjK+xu7nG8nGIcLhHp88YSPZRd4kW7K9E+hjNFU3JthqPooPB469c+tQu6cuS5XDQT66yln9GEmlB0fFzf329a+sIcLhHh3m+y+4Qm5TmR5X.oVWy0bMwQdjGYRGin0st0wu7W9KS5X.oVETPAw+8+8+cRGiHhH9+8+6+WzktzkjNFPp0UdkWYLfALfjNFQqZUqh+8+8+8jNFPpU94mesl4F7O7O7ODcu6cOoiAjZc4W9kGG6wdrIcLhVzhVD+leyuIoiAjZkWd4E29se6IcLhHh3m7S9IQu5UuR5XP8X1pdqgUWXq5c6N2y8biW3EdgDa76cu6cL24N2ngMrgIVF.h3Mey2LFzfFTTVYkkXY39tu6Ktlq4ZRrwGXaF9vGd7rO6ylXieO5QOh28ceWWOCgD1rl0rhi4XNlDctA28ce2w0dsWahM9.aykbIWR7jO4SlXieW6ZWi268dunIMoIIVF.hXNyYNw.Fv.hRKszDKC2wcbGwO5G8iRrwGXa9NemuSL5QO5Da76bm6b79u+66ZcLYTVwooX2+8e+Q6ae6SjwtgMrgwi8XOlRSgZAF3.GXhtZOujK4RTZJTKw8ce2WzwN1wDYraPCZP73O9iqzTnVfi5nNpDcEcL7gObklB0RbO2y8jXWNMJnfBhG+webklB0Bz+92+3lu4aNwF+y67Nu35u9qOwFef+O20ccWI1k5m7yO+3wdrGSoojwo3zTr1111FO9i+3QCZPCx5i8cbG2QbTG0Qk0GWfcsa3Ftg3bO2yMqOt8oO8I98+9eeVebA10NfC3.hQO5QmH+gMc629sWqX6AEXa9Y+reVL7gO7r931qd0q3AdfGHqOt.6ZsoMsIdhm3IhF0nFk0G6e6u82VqX6AEXa9G9G9GhK9hu3r931idzi3AevGrJ6xe.IiBKrv3O8m9SIxezy+m+m+mwfG7fy5iKoOJNMk6DOwSLdjG4Qh7xKur1Xdi23MF+fevOHqMd.6Y4jSNwnG8nii+3O9r1X1oN0oXBSXBQKZQKxZiIvd1fG7fiG6wdrr5bC9m+m+miq65ttr13ArmkSN4DO5i9nwIdhmXVaL6PG5PLgILgnksrkYswDXO6XO1iMF8nGcje94m0Fya3Ftg3u4u4uIqMd.6cd3G9gigLjgj0Fu10t1ESXBSHJrvByZiIvd1.Fv.hwLlwDETPAYsw7m8y9Ywe2e2eWVa7HcSwoDWxkbIwC7.OPV4C5F0nFU7u9u9ulwGGf8cMoIMIF6XGaVo7ztzktDSbhSLw11u.18tvK7BiG5gdnrxtRwO+m+yie0u5WkwGGf8cMtwMNF6XGaVo7zN24NGSbhSLw11u.18N+y+7iG4QdjrxtRwO8m9SSzsKbfpWiZTihm64dtrR4ocricLl3DmXz8t28L9XAru6rO6yNqco36u6u6uKtka4Vx3iCrcJNkHhHt7K+xiwMtwEspUsJib9KnfBh64dtm3e+e+eOib9ApYzpV0pXhSbhwkdoWZFaLF3.GXLiYLin28t2Yrw.X+22869ciW5kdoL1ec24me9wcdm2Y7e7e7ejQN+.0LZQKZQ7xu7KGe2u62MiMFG0QcTwLlwLh9129lwFCf8eW5kdowDlvDhV25VmQN+4kWdw+6+6+abq25slQN+.0LZdyadL9wO93xu7KOiMFequ02JlwLlQbHGxgjwFCf8eW7EewwDm3DiC3.NfLx4Ou7xKtsa61ha61tsLx4GpNJNkJbpm5oFyYNyoF+uZr9129FSe5SO9g+veXM54EHynQMpQwnG8ni64dtmZzK154latw+3+3+XLsoMs3fO3CtF67Bj4LzgNzXtyctwobJmRM54s28t2wq+5udLxQNxZzyKPlQCaXCiG8Qez3du26MZVyZVM14MmbxI9o+zeZ75u9qGsqcsqF67Bj4bRmzIEyctyMF1vFVM54sm8rmwq8ZulsmWnNhFzfFDOzC8Pw8e+2ez7l27ZryaN4jS72+2+2GyXFyH5PG5PM14EHy4DNgSHl6bmabFmwYTidd6d26dL0oNUaOujHTbJURm6bmiW4Udk3AdfGH5Tm5z904pksrkwMcS2TL6YO63nO5itFJg.YK+ve3OLdu268hu2266E4jSN6WmqgLjgDyblyLt4a9lyJa8m.0b19Vj0C8POz981qcKZQKhe8u9WGuy67Nw.G3.qgRHP1xO3G7Ch2+8e+3JthqX+dtAmzIcRwa7FuQbq25slU1du.p4zgNzgX7ie7wi7HOx981qcyadyie0u5WEyYNyIN1i8XqYBHPVyUcUWU79u+6GW4UdkQt4t+8qY9DNgSHl9zmd7a+s+VyM.piocsqcw3F23hG6wdrnacqa6Wmql0rlE+a+a+awbm6biAO3AWCkPXeSNkWd4kmzgn9jc9WfPc4Wd27l2bL5QO53tu66NlwLlwd8iqO8oOwO7G9Ciq5ptJW71g5I9fO3Ch67Nuy3QdjGIV8pW8d0ioQMpQwvG9viq+5u9rx0FMfLuhKt33IdhmHtq65thYLiYrWOOmd26dWwbCxTaue.YWe3G9gwccW2U7vO7CGqZUqZu5wzvF1v3BtfKHt9q+5iS9jO4LbBAxF1xV1R7DOwSD28ce2wq+5u9d8bC5Uu5ULhQLh3pu5qNZSaZSFNk.YCe7G+wwcdm2Y7POzCsOM2fy67Nu35u9qOF5PGZFNg.YCaYKaIFyXFSbW20cEu1q8Z60yMnG8nGwHFwHhq4ZtlL1V+Kr2Rwo0vpOUb5N5q9puJF+3GeLqYMq3C9fOH95u9qihJpnnwMtwQgEVXzm9zmn+8u+wvF1vbcKDpGqzRKMl9zmdLkoLkXdyadwBW3Bi0st0EkUVYQKZQKhNzgNDG1gcXwfFzfhgNzgFMoIMIoiLPFxW8UeULgILgXVyZVw6+9u+tbtAGwQbDwvF1vh9zm9jzwEHCorxJqJyMXsqcsUZtAG5gdnwfFzfhS4TNEyM.pGaoKcowDlvDh29se63C9fOHVwJVQklaPu6cuqXtAtlFC0eUVYkEyXFynh4FrfErfJM2f1291Wo4FTSdIBBn1kksrkUwbC19u2f0u90GMtwMNZUqZUklaP+5W+R53BUPwo0vpuVbJ........Telqwo.........odJNE........H0Swo.........odJNE........H0Swo.........odJNE........H0Swo.........odJNE........H0Swo.........odJNE........H0Swo.........odJNE........H0Swo.........odJNE........H0Swo.........odJNE........H0Swo.........odJNE........H0Swo.........odJNE........H0Swo.........odJNE........H0Swo.........odJNE........H0Swo.........odJNE........H0Swo.........odJNE........H0Swo.........odJNE........H0Swo.........odJNE........H0Swo.........odJNE........H0Swo.........odJNE........H0Swo.........odJNE........H0Swo.........odJNE........H0Swo.........odJNE........H0Swo.........odJNE........H0Swo.........odJNE........H0Swo.........odJNE........H0Swo.........odJNE........H0Swo.........odJNE........H0Swo.........odJNE........H0Swo.........odJNE........H0Swo.........odJNE........H0Swo.........odJNE........H0Swo.........odJNE........H0Swo.........odJNE........H0Swo.........odJNE........H0Swo.........odJNE........H0Swo.........odJNE........H0Swo.........odJNE........H0Swo.........odJNE........H0Swo.........odJNE........H0Swo.........odJNE..9+m8tOi1JqNWa.+r2TTjtHV.UTTAjdrfkfsXugwBpXrAQPvRTIgn9YKQhwbxIpQEQriwJhcEPhJVPiFIhnhfkfHVHpXihhz+9QFGRPPDk0ZMW68755eNF606y8vw3cxbsteK......j8TbJ........P1Swo.........YOEmB........j8TbJ........P1Swo.........YOEmB........j8TbJ........P1Swo.........YOEmB........j8TbJ........P1Swo.........YOEmB........j8TbJ........P1Swo.........YOEmB........j8TbJ........P1Swo.........YOEmB........j8TbJ........P1Swo.........YOEmB........j8TbJ........P1Swo.........YOEmB........j8TbJ........P1Swo.........YOEmB........j8TbJ........P1Swo.........YOEmB........j8TbJ........P1Swo.........YOEmB........j8TbJ........P1Swo.........YOEmB........j8TbJ........P1Swo.........YOEmB........j8TbJ........P1Swo.........YOEmB........j8TbJ........P1Swo.........YOEmB........j8TbJ........P1Swo.........YOEmB........j8TbJ........P1Swo.........YOEmB........j8TbJ........P1Swo.........YOEmB........j8TbJ........P1Swo.........YOEmB........j8TbJ........P1Swo.........YOEmB........j8TbJ........P1Swo.........YOEmB........j8TbJ........P1Swo.........YOEmB........j8TbJ........P1Swo.........YOEmB........j8TbJ........P1qloN.T0xG8QeTL4IO43S9jOIlyblSTm5TmnwMtwQqacqiMdi23nhJpH0QDnDX9ye9wa7FuQ7Nuy6DyZVyJVzhVTzfFzfn4Mu4Qaaaai5V25l5HBTh7we7GGSZRSxdCfL2BVvBV5dCl4Lm4R2aPyZVyh10t1YuAPF4i+3ONl7jmbLiYLikYuAspUsJZQKZg8F.YhErfEDu4a9lwTm5TWt8Fz1111nd0qdoNh.kHyXFyXo+tAyd1yNpScpSznF0nnUspUwlrIah8FPYGEmxJ0hVzhhQMpQE268duwnG8nioO8o+s921nF0nXO1i8H5V25VbXG1gE0oN0oDlTfhs2+8e+31tsaKFwHFQ77O+yGKXAKXE92UQEUDcricL1u8a+hdzidDcnCcnDmTfhoEu3EGiZTiJtu669hQMpQsR2aPCaXCW5dC5d26t8F.Uy7AevGrz8F7bO2ysR2aPG5PGV5dC5XG6XINo.ESKdwKNF8nGcbu268FiZTiJ9fO3C9V+aaXCaXr669tGG3Adfwge3GdrVq0ZUBSJPw1zm9zW5dC9a+s+1JcuAsu8sO128ceidzidDctyctDmTfhokrjkrL6M38e+2+a8usAMnAKydCbAWR4fJVxRVxRRcHpN4ad0QTU8+8N+4O+3pu5qNtzK8Ri28ce2u2e9F23FGm3IdhwYdlmYznF0nhPBAJUl3DmXbAWvEDOvC7.whVzh9d+42ocZmhy+7O+XO1i8nHjNfRkErfEDCYHCItjK4RhoMso889y23F23n28t2wYcVmUz3F23hPBAJUlzjlTbAWvED2+8e+wBW3B+d+4+w+3ebb9m+4G60dsWEgzATprfErf3Zu1qMtjK4RhoN0o989y2nF0nkt2f0dsW6hPBAJUd8W+0iK3Btf3du268GzdC1gcXGhy+7O+Xe1m8oHjNfRkEtvEFW20ccwe5O8mh29se6u2e9F1vFFmvIbBwYe1mczjlzjhPBgUMJNs.q5PwoidziNNoS5j9As312TSZRShK9hu3n28t2EfjATJM6YO6X.CX.w0ccWWr3Eu3U6i29tu6aLjgLjXi23Mt.jNfRoG8Qezne8qewTlxTVsOVMtwMN98+9eez2912BPx.JklyblS7q+0+53Zu1q8GzES02zdsW6UbsW60FsnEsn.jNfRowLlwD8su8Mdq25sVsOVMpQMJtnK5hhS5jNoBPx.Jk9xu7Kiy7LOyXHCYHEj8FrG6wdDW60dswltoaZAHc.kRO4S9jwIdhmX7lu4atZerZXCaXLvANv3TNkSwiwWRBEmVfUUt3zErfED8u+8OFzfFTA+Xe.GvAD27MeytJRgpH96+8+dzidziePW43qLMrgMLtlq4Zhi3HNhB5wEn3XAKXAw.Fv.hq3JthB9dZlPJ71L...B.IQTPT0u8a+h+xe4u3pHEphXbiabQO5QOJHW.E+2ZPCZPLjgLjnG8nGEziKPwwBW3Biy7LOy3xtrKqfu2f8du263VtkaIZZSaZA83BTb7hu3KF8nG8nfbAT7eq90u9wfG7fii9nO5B5wEn3XQKZQwYe1mcbIWxkTPtwK9usm64dF25sdqw5ttqaA83BeWTbZAVU0hSm4LmYbHGxgDiYLionMiV25VGibjiLZYKaYQaF.q9t669tii4XNl3q+5utnMiK7Buv37Nuyqnc7AV8MqYMq3POzCMdrG6wJZyXK1hsHF4HGYr4a9lWzlAvpu669tu3m8y9Ywbm6bKZy3BtfKH9M+leSQ63Cr5a1yd1Q26d2iQO5QWzlwlsYaVLxQNxnUspUEsY.r56AevGL5QO5Q7Ue0WUzlw4bNmS769c+th1wGX02blybhi3HNhXjibjEsYroa5lFibjiLZSaZSQaFv2jhSKvpJVb5Lm4Lica21s3kdoWpnOq0e8W+Xricr9ARgxT+k+xeIN9i+3KIqc0+92+3RtjKonOGfu+l0rlU7S9I+j3EewWrnOq0ccW2Xricr9ARgxT29se6wwbLGSA+pGeE4W7K9Ewke4WdQeN.e+Mm4LmX228cOdgW3EJ5ypoMsowS+zOsefTnL0vF1vhi5nNpRxdCNoS5jhq5ptph9b.996K+xuL1i8XOhm+4e9h9rZRSZR7TO0SEsqcsqnOKHhHpL0AfzZtyctwAb.GPIozzHh3C+vOL1y8bOioO8oWRlGvptG3AdfnW8pWkrK3iK8RuTW8nPYnu9q+53.OvCrjTZZDQ7we7GG64dtmw6+9ueIYd.q5d3G9gii63NtRxOLZDQbEWwU3tNEJCMu4MunacqakjRSiHhYLiYD64dtmw69tuaIYd.q5djG4QJYWPUQDwfG7fiy8bO2Rxr.V0M+4O+3m9S+okjRSiHhO8S+zXu1q8Jdm24cJIyCbGmVfUU6NNsW8pWwMcS2TIeta+1u8wS+zOcTqZUqR9rAVdSdxSN5RW5RLm4LmR9ru+6+9iC5fNnR9bAVw5Se5SbcW20UxmaW5RWhwN1wF0t10tjOafk2a9luYrMay1Dyd1ytjO664dtm3PNjCojOWfUr90u9ECYHCojO2sdq253Ye1mMVi0XMJ4yFX48O+m+yXa1lsIl4LmYIe1CaXCKN7C+vK4yEXE6TO0SMFzfFTIetctycNdtm64h0bMWyR9rIu3NNMiMzgNzjTZZDQ77O+yGm0YcVIY1.Kq4N24FG1gcXIozzHh33O9i2ULFTl3Vu0aMIklFQDuvK7Bw.Fv.RxrAVVyadyKNrC6vRRooQDQO6YOi29se6jLafk0cdm2YRJMMhHdwW7Ei92+9mjYCrrl+7mez8t28jTZZDQbBmvIDu0a8VIY1.Kq69tu6jTZZDQLgILg3zNsSKIyl7h63zBrpJ2woezG8QQaZSahu3K9hjkgJqrx3u829aw1scaWxx.PDmy4bNwu+2+6SZF1m8YehQMpQkzL.4tYLiYDsoMsI9rO6yRVFpnhJhm4YdlXG2wcLYY.HhK3Btf3BuvKLoYXO2y8L9q+0+ZRy.j69zO8SiV25VGe5m9oIKCUTQEwS9jOYry67NmrL.Dw.G3.iy+7O+jlgca21sXLiYLIMCPt6y+7OOZSaZS7we7GmzbLlwLlX21scKoYfp2bGmlo9k+xeYRKMMhHV7hWbz2912R16EAfk2q+5ud7+9+9+l5XDOxi7Hwce22cpiAj0Fv.FPRKMMh+8EbVe6aeiEsnEkzb.4r25sdq3O7G9CoNFwi9nOZbm24cl5X.Yse8u9WmzRSi3eu2f90u9EKbgKLo4.xYSYJSI4Wr0QDwS7DOQbq25sl5X.Ysy5rNqjWZZD+6Wi.KXAKH0wfpwbGmVfUU3NN8Ue0WM5Tm5TYS1t8a+1idzidj5X.Yoi3HNh3ttq6J0wHhHhV25VGSZRSJprRWSOPo1jm7ji1291mjKloo0tsujOS..JMZwq87EjiyMcS2Tb7G+wWPNV.e+bbG2wE+k+xeI0wHhHhMcS2z3Mey2LpYMqYpiBjclxTlRzl1zlxlKloq65tt3DNgSH0wfpo7qSmgF3.GXYSooQT9kGHWLoIMoX3Ce3oNFK0a7FuQLrgMrTGCHKMvANPOAH..nr0u62867Do.Rf+4+7eF21scaoNFK0Tm5Tia4VtkTGCHKcQWzEU1TZZDke4gpWTbZlY5Se5w8du2apiwxXxSdxwi+3OdpiAjcF7fGbY2EsvUdkWYpi.jc9nO5iJqtHJ..fuooLkoDiZTiJ0w.xNCYHCor6hVXPCZPoNBP14y9rOKt8a+1ScLVFuy67NwHFwHRcLnZJEmlYF5PGZY2FdhHhq+5u9TGAHqL24N2xpqZz+OO2y8bwjlzjRcLfrxPG5PcUZB.PYO+tAPo07m+7KadD89ea7ie7w3G+3ScLfrxsbK2RLu4MuTGiky0ccWWpi.USo3zLS45iAyG7Aev3q+5uN0w.xF+0+5eM9hu3KRcLVgJWdmqB4BmyA.PUAiZTiJl8rmcpiAjMdhm3IhYLiYj5XrB46v.kVkqmyM5QO5XlybloNFTMjhSyHu268dwq7JuRpiwJzbm6biwLlwj5X.YiG9ge3TGguUkyYCptY5Se5wK8RuTpiA..7cZ9ye9wi9nOZpiAjMJm+t4kyYCpt4S9jOId9m+4ScLVgV3BWXL5QO5TGCpFRwoYjG6wdrTGgUpx87AUmTNe913G+3iO+y+7TGCHK73O9iW18tNF..91TN+8XfpaJmOe60dsWK9vO7CScLfrvS7DOQr3Eu3TGiuUkyqUQUW0L0AfRmwMtwk5HrRcYW1kEW1kcYoNF.I1RVxRh+w+3eD64dtmoNJP0dk66M...9uYuKPowrl0rh23MdiTGiUpMXC1fTGAfx.1a.ECtiSyHdwoCTUg0qfRCmqA.PUIuxq7JwBW3BScLfp8lvDlfmLM.UILwINwX9ye9oNFTMihSyHu8a+1oNB.rJw5UPogy0..npj4O+4GevG7AoNFP0d9dB.UUrvEtv38du2K0wfpYTbZlXtyctwLlwLRcL.XUxzl1zRcDfp8l+7mu2KP..Tkiuq.T747LfpRrlEEZJNMS74e9mm5H.vprO6y9rTGAnZuu3K9BO9s..nJG+9FPwmyy.pJwZVTno3zLwW8UeUpi..qxrlET747L..pJ5K+xuL0Q.p1y4Y.UkXMKJzTbZlXgKbgoNB.rJaQKZQoNBP0d1a...UE46J.EeNOCnpDqYQglhSyDq0ZsVoNB.rJyZVPwmyy..npH6gAJ9bdFPUIVyhBMEmlIpe8qepi..qxpW8pWpi.Tsm8F..PUQ9tBPwmyy.pJwZVTno3zLQiabickW.TkwFtgaXpi.TsW8qe8iFzfFj5X...eu36J.EeazFsQoNB.rJyZVTno3zLRKZQKRcD.XUxlrIaRpi.jEr2...ppw9WfhOmmATUh0rnPqloN.T5zgNzgXxSdxoNF.7cp8su8oNBPVnCcnCwq9puZRyPKdsmOoyG.fpN1jMYS733CJA7cxAppXC2vMLZXCaXpiAUy3NNMirMay1j5H.vpjsca21TGAHKXuA..TUhum.TZrIaxlDMsoMM0w.fuS1a.ECtiSyH6zNsSoNBqTWy0bMQe5SeRcLfrv9se6WLpQMpTGiUn0e8W+Xy27MO0w.xBk66M3ptpqJNoS5jRcLfrP25V2hG5gdnTGiUnl1zlFezG8QQEUTQpiBTs2DlvDhezO5Gk5X7spqcsqoNBP1nqcsqw8ce2WpiwJzZu1qcLiYLinxJcOAAEaSbhSL5PG5Ppiw2px8eWCpZx+5RFoKcoKk0WsX6+9u+oNBP1nb97sx4rAU2r0a8VGq+5u9oNFeqrd.T5TNe919se6mRSgRjN24NGMu4MO0w3a0Ab.GPpi.jMJm2av9tu6qRSgRj1291Ga7FuwoNFeqJmWqhpt7uvjQprxJiC7.OvTGiUnsYa1lx5ubFTcS25V2Ja+RFGzAcPoNBP1nhJpH5V25VpiwJTm6bmiVzhVj5X.YiC7.OP6M.Hhn78bt1291GsrksL0w.xFGvAb.QMpQMRcLVgJWWmBptpb8bt1zl1DspUsJ0wfpgJO+lwTzzqd0qTGgUnx0bAUWsQazFE6wdrGoNFKmMXC1fXe228M0w.xJkq+avkq4BptpYMqYw9rO6SpiwxYcW200cXFThUt9uAWtlKn5p0a8Vuxx6jqlzjlT1VhCTcU45+Fb4ZtnpOEmlY9w+3ebzt10tTGikQ8pW8hi5nNpTGCH6TN9NEtW8pWQMqoW+1Poz1scaWzwN1wTGikwZsVqUbzG8Qm5X.Ymxw8Fzyd1ynV0pVoNFPVYq25sN1psZqRcLVFq4ZtlwwdrGapiAjcJG2avwe7GeT6ZW6TGCHqz4N24nKcoKoNFKi0XMVi33NtiK0wfpoTbZF5+2+u+eoNBKiS9jO4ngMrgoNFP14fO3CN1xsbKScLVp5V25Fm1ocZoNFPV5bNmyI0QXYzu90unwMtwoNFP1oacqaQ6ae6ScLVp5Tm5DmwYbFoNFPVpbauAm3IdhQSZRSRcLfry9se6Wz4N24TGikZMWy0L5e+6epiAjkJ25T3DNgSHV20ccScLnZJEmlgNxi7HKaJKo90u9wu5W8qRcLfrTkUVYbAWvEj5XrTm7IexQSaZSScLfrzgcXGVYSYI0st0M90+5ecpiAjkpnhJheyu42j5XrT8qe8KVu0a8RcLfrzAevGbzoN0oTGiHh+8Shhy7LOyTGCHKUts2f9zm9DMqYMK0w.xRGzAcPkMOQJVy0bMiy9rO6TGCpFSwoYnJqrx3JuxqL0wHhHhK7BuvXcVm0I0w.xVGwQbDwttq6ZpiQz7l273bO2yM0w.xVUVYkwfFzfRcLhHh329a+stpQgD5POzCM18ce2ScLhMXC1f37O+yO0w.xVUTQEwfFzfhJpnhTGk37O+yO1fMXCRcLfr0AcPGTr268dm5XDq25sdwu829aScLfr1UcUWUYwdCN2y8bil27lm5XP0XJNMSs669tm72OHa8Vu0wodpmZRy.PDW8Ue0wZtlqYRyvUdkWYT+5W+jlAH2sK6xtD8pW8JoYnyctydjcCkAt5q9pi5Tm5jzLb4W9k604AjXcsqcMNgS3DRZF5PG5fGKmPYfAO3AGq0ZsVIMCW1kcYQiZTiRZFfb21u8aez2912jlg1111FCX.CHoYfp+TbZFaPCZPQqZUqRxraXCaXbm24cF0nF0HIyG3+nMsoMwUbEWQxle+5W+hC9fO3jMef+iK+xu7nMsoMIY10u90OF1vFVTyZVyjLef+isXK1h3ptpqJYyu28t2Q26d2S17A9O9y+4+bzt10tjL65Uu5E20ccWQspUsRx7A9OZYKaYLjgLjjM+d1ydF8nG8HYyG3+3RtjKI5XG6XRl8ZsVqUbW20cE0t10NIym7ghSyX0u90Ot669tK42kWUVYkwMey2br4a9lWRmKv2td26dmj6zrsa61t3xtrKqjOWfUr5Uu5E2y8bOk76xqJqrx3ltoaJYWPW.Kud1ydF8oO8ojO2sca21jdAcArrVq0Zsh69tu6R9c4UEUTQbC2vMjrKnKfk2wbLGSbRmzIUxm6VsUaURuft.VV0oN0IF9vGdz3F23R5bqnhJhq65ttjcAcQdQwoYtNzgNDO3C9fkzGSmCYHCINnC5fJYyCXUy0bMWSzst0sR17ZW6ZWLxQNxXMVi0njMSfuassssMdnG5gJoOlNGzfFTbnG5gVxlGvplAO3AWRepPrka4VFibjiL4uBA.VVsoMsIFwHFQI8wz4ke4Wdb3G9gWxlGvplq7JuxR5SEhV25VGOxi7HI+UH.vxpUspUwnF0nh5Uu5Uxl4kdoWZbTG0QUxlG4MEmRrq65tFOvC7.E867zZTiZDCdvCN5cu6cQcN.+vTyZVyXXCaXkjefzN24NGO1i8XwZu1qcQeV.e+sS6zNEOzC8PQCZPCJpyoxJqLtxq7Ji90u9UTmCvOL0nF0Hti63NhC6vNrh9r5XG6X7XO1iEqy5rNE8YA782Nti6XLhQLhh9SkhJqrx3xtrKKN0S8TKpyA3GlJqrx3Vu0aMNhi3HJ5yp8su8wi8XOVzzl1zh9r.99a61tsKFwHFQQ+NOshJpH9S+o+Tb5m9oWTmC7eSwoDQDwdsW6UL1wN1Xi23Mtnb7aPCZPbe2284GFEJyslq4ZF28ce2Q+6e+KZyX+2+8OF6XGar9q+5WzlAvpuce2283YdlmIZQKZQQ43W+5W+3dtm6INkS4TJJGefBi0XMVi3ttq6JFv.FPQaF669tuwXG6Xil0rlUzlAvpuccW203Ye1mM1zMcSKJG+5V25FCe3C2OLJTlq10t1wcbG2QbVm0YEUTQEEkYrW60dEOyy7LwFtgaXQ43CTXry67NGO6y9rwlsYaVQ43W25V2XXCaXwu7W9KKJGe3aihSYo5Tm5T7xu7KWvuk22ocZmhW9ke43.OvCrfdbAJNprxJiK4Rtj3ge3GNVu0a8JXG25Tm5DWwUbEwC8POTI8Q4AvObcnCcHd4W9kii9nO5B5wcG2wcLlvDlP7S+o+zB5wEn3nhJpH9i+w+XLpQMpB5E9zZtlqYbYW1kEiXDinneGtCTXzt10tXBSXBwwcbGWA83t8a+1GSXBSHNjC4PJnGWfhiJpnh3hu3KNdjG4QJnW3SqwZrFwkbIWR7HOxiTzuC2AJL1xsbKiILgID8pW8pfdb6RW5R7RuzKURe7fC+eTbJKiF0nFE21scawi8XOVrUa0VsZcrZQKZQbK2xsDO0S8TwlrIaRgIf.kL6+9u+wa7FuQblm4YtZ8tFqhJpHN5i9niW+0e83TO0SsncEoBTbzvF1v3VtkaIFyXFSr0a8VuZcr1nMZiha9lu4XricrQKaYKKPIDnTYe1m8Idi23Mhy9rO6Uq20XUTQEwQcTGUL4IO43zO8S2dCfpXZPCZPLzgNz3odpmJ11scaWsNVa3FtgwMcS2T7rO6yFa9lu4EnDBTprW60dEu9q+5w4bNmyp06A4Jpnh3HOxiLl7jmbz+92e6M.phod0qdwMbC2PL1wN1X61tsa05X07l273FtgaHdtm64hsXK1hBTBguepXIKYIKI0gn5ju4+vdU4+26RVxRhwLlwDCYHCIF4HGY7Ue0W8c9YpYMqYrK6xtD8oO8IN3C9fiZUqZUBRJPw1m7IeRbC2vMD27Meywjm7jWk9LMu4MO5QO5Qz2912h1irCfRum3Idh3pu5qNF4HGY7ke4W9c92WyZVyXm24cN5Se5SbHGxgXuAP0De5m9owMdi2XLzgNzXRSZRqRell0rlEG4QdjQe6ae8if.Ui7jO4SFCYHCIFwHFQLm4Lmuy+9ZVyZF6zNsSQu6cuiC8POzn10t1kfTBTr8Ye1msz8F7Zu1qsJ8Y1fMXChi3HNhne8qeQqZUqJxIDnT4oe5mNt5q9piG9ge3Uo8FTiZTinqcsqQu6cuit28tauAjbJNs.q5Two+2l27lWL1wN1X7ie7wjm7jiO4S9jXNyYNQcpSchF23FGst0sN5Tm5Trq65t5QoATM2Tm5Tim5odpXhSbhw67NuSLqYMqXQKZQQCZPChl27lGsu8sO1gcXGhN0oNk5nBTDMu4Mu3YdlmIF+3GeLoIMokauAspUsJ5Tm5Tra61tYuAP0buy67NKydCl4Lm4R2aPyZVyV5dC5bm6bpiJPQz7m+7Wle2fYLiYrb6Mnicriwtsa6VznF0nTGWfhnoMsosz8FL0oN0kauAsqcsao6MvcWJT807m+7Wle2f+68FznF0nkYuAMtwMN0wEVJEmVfUcs3T........n5LuiSA........xdJNE........H6o3T........frmhSA........xdJNE........H6o3T........frmhSA........xdJNE........H6o3T........frmhSA........xdJNE........H6o3T........frmhSA........xdJNE........H6o3T........frmhSA........xdJNE........H6o3T........frmhSA........xdJNE........H6o3T........frmhSA........xdJNE........H6o3T........frmhSA........xdJNE........H6o3T........frmhSA........xdJNE........H6o3T........frmhSA........xdJNE........H6o3T........frmhSA........xdJNE........H6o3T........frmhSA........xdJNE........H6o3T........frmhSA........xdJNE........H6o3T........frmhSA........xdJNE........H6o3T........frmhSA........xdJNE........H6o3T........frmhSA........xdJNE........H6o3T........frmhSA........xdJNE........H6o3T........frmhSA........xdJNE........H6o3T........frmhSA........xdJNE........H6o3T........frmhSA........xdJNE........H6o3T........frmhSA........xdJNE........H6o3T........frmhSA........xdJNE........H6o3T........frmhSA........xdJNE........H6o3T........frmhSA........xdJNE........H6o3T........frmhSA........xdJNE........H6o3T........frmhSA........xdJNE........H6o3T........frmhSA........xdJNE........H6o3T........frmhSA........xdJNE........H6o3T........frmhSA........xdJNE........H6o3T........frmhSA........xdJNE........H6o3T........frmhSA........xdJNE........H6o3T........frmhSA........xdJNE........H6o3T........frmhSA........xdJNE........H6o3T........frmhSA........xdJNE........H6o3T........frmhSA........xdJNE........H6o3T........frmhSA........xdJNE........H6o3T........frmhSA........xdJNE........H6o3T........frmhSA........xdJNE........H6o3T........frmhSA........xdJNE........H6o3T........frmhSA........xdJNE........H6o3T........frmhSA........xdJNE........H6o3T........frmhSA........xdJNE........H6o3T........frmhSA........xdJNE........H6o3T........frmhSA........xdJNE........H6o3T........frmhSA........xdJNE........H6o3T........frmhSA........xdJNE........H6o3T........frmhSA........xdJNE........H6o3T........frmhSA........xdJNE........H6o3T........frmhSA........xd0L0AfpNl6bmaLoIMoXxSdxwm7IeRLm4LmnN0oNQiabiiV25VGsu8sOZXCaXpiIPIv68duW7Zu1qEScpSMl0rlUrnEsnnAMnAQyadyi1291Ga1lsYQkU5ZyApt6q+5uNlzjlTLoIMI6M.xbu+6+9wDm3Di24cdmXlyblKydCZW6ZWr4a9lauAPF3+auASdxSNlwLlwxr2fV0pVEsu8sOZTiZTpiIPIvG7AePLwINwXpScpKydCZVyZVzt10tXK1hsvdCfLv7l27Vle2fYO6YG0oN0IZTiZTzpV0pnCcnC1a.kcTbJqTyd1yNtsa61h669tu3odpmJl27l225eakUVYzktzknacqaQO6YOi0e8W+RXRAJ19G+i+Qby27MGiXDiHl5Tm5J8usoMsow9rO6SzidziXe1m8IpnhJJQoDnXaNyYNKcuAO4S9jem6MXa21sco6MXC1fMnDlTfhswO9wGCcnCMFwHFQ71u8auR+aWm0YcVl8F3GJEp93K+xuLt8a+1i68du23IexmL95u9q+V+aqrxJisYa1lkt2fl0rlUBSJPw1K8RuzR2avTlxTVo+sMoIMI168duidzidD629se1a.TMxW9keYbG2wcD268duwS7DOwJcuAUTQEw1rMaSbfG3AF8rm8L1vMbCKgIEVwpXIKYIKI0gn5juY4.UU+eue9m+4wu+2+6iq4ZtlX1yd1eu+70pV0JNxi7HiK7BuvXS1jMovGPfRlG8Qez3bO2yMdgW3E9A842rMayhy8bO23XO1i0WDBpB6K9huHt3K9hiq9pu5eP6Mnl0rlwQbDGQLvANvXS2zMsHjPfRkG+we73bO2yMd9m+4+A842zMcSiy8bO233O9i2dCfpvl4LmY7G9C+gXvCdvwrl0r9d+4qYMqYz8t28XfCbfwlsYaVQHg.kJOwS7Dw4dtma729a+sePe9MYS1j3bNmyI5YO6YTiZTiBb5.JUl0rlU7+7+7+DW0UcUwLm4L+d+4qQMpQbXG1gE+te2uK17MeyKBIDV0n3zBrpCEmdi23MF+pe0uJ97O+yWsOVqwZrFwYdlmYbdm24E0rltAmgpRl9zmdzm9zmXDi35jmjA..f.PRDEDUXDEjiWm5TmhgNzgFctyctfb7.Jct4a9li92+9Ge1m8Yq1GqZW6ZGCX.CHtfK3BhZUqZU.RGPoxG9geXzm9zm3gdnGpfb75PG5PLzgNzXq1pspfb7.Jctka4Vhy3LNi3S+zOc09XUqZUq3W8q9Uwu427ahZW6ZW.RGPoxG8QeTbhm3IFOvC7.EjiW6ae6ia5ltoXa1lsofb7.Jct8a+1iS6zNs3S9jOY09XUqZUq3LNiyHF3.Gn8FPRn3zBrpxEmN6YO633NtiKtu669J3G6sca21X3Ce3QKZQKJ3GafBuG5gdn33O9iufTRx+sZW6ZGW7EewQ+6e+KnGWfhi4Lm4DG+we7w8bO2SA+Xu0a8VGCe3C2ceJTEwHG4Hii8XO1BRII+2pUspUbQWzEECX.CnfdbAJN9xu7Kid0qdE20ccWE7i8O5G8ihgO7g6tOEph3QdjGIN1i8XiYLiYTPOt0rl0LF3.GXbVm0YUPOt.EGe0W8UwIbBmPbG2wcTvO1cpScJF9vGdrEawVTvO1vJihSKvppVb56+9uer+6+9Guxq7JEsYr9q+5GO7C+vwVu0acQaF.q9thq3Jhy3LNiXwKdwEsYzm9zmXvCdvdD7.kwl9zmdr+6+9GSXBSnnMi0ccW23ge3GN11scaKZy.X02fG7fiewu3WDKZQKpnMie9O+mGCYHCwSoFnL1G9geXb.GvADu3K9hEsYzzl1z3AevGL19se6KZy.X020bMWSbxm7IWT2avwe7GebsW605oTCTF6i9nOJNvC7.iwMtwUzlQSZRShG7AevXG2wcrnMC3aRwoEXUEKNc5Se5QW6ZWioN0oVzmU8qe8iwLlw3QtATl5O9G+iwYdlmYIYV8nG8Ht0a8V8tMCJC8ge3GFcsqcMlxTlRQeV0qd0Kd7G+witzktTzmEv2eW5kdowu7W9KKIy5vO7COti63Nr2.nLzG+webz0t103sdq2pnOq5V25FO5i9nwNrC6PQeV.e+c4W9kGm9oe5kjYcnG5gFCaXCyEcMTFZFyXFwNuy6b75u9qWzm0ZsVqUL5QO5nqcsqE8YAQn3zBtpZEm94e9mGcsqcMlzjlTIalqy5rNwy7LOSz5V25R1LA9tc8W+0G8t28tjNyS5jNo3ptpqpjNSfUtYNyYF6zNsSwq9puZIalq8Zu1wXG6Xi1111VxlIv2sa5ltonW8pWkzY1m9zm3ZtlqojNSfUtYMqYE67NuywK+xubIalMpQMJF6XGaz9129R1LA9tcK2xsDG2wcbkzeuyd0qdE2vMbCkr4A7caNyYNwtrK6RL9wO9R1LaXCaX7zO8SGcricrjMSxWJNs.qpTwoKYIKINnC5fhG5gdnR9r2xsbKiwMtwE0st0sjOafk2e+u+2icZm1oXAKXAk7Ye8W+0G+7e9OujOWfUrC9fO339u+6ujO2V25VGiabiKpe8qeIe1.KuwMtwEcsqcMl+7meIe1CYHCINwS7DK4yEXEq6cu6wce22cIeta9lu4wK9huXzfFzfR9rAVdie7iO1wcbGi4Mu4Uxm8fFzfhS9jO4R9bAVwNxi7HigMrgUxmaKaYKiW7EewnQMpQk7YSdwy.oL1kbIWRRJMMhHl7jmbbRmzIkjYCrr9hu3Kht28tmjRSiHhS4TNkXhSbhIY1.Kq+7e9OmjRSiHh23Mdinu8suIY1.KqYMqYEcu6cOIklFQDm1ocZkz6rMfucCZPCJIklFQD+y+4+rj+DwAXEaNyYNQ26d2SRooQDQ+6e+Ko2Ya.e6FxPFRRJMMhHd629scyWPIg63zBrpJ2wou8a+1Q6ae6i4N24lzbL5QO5Xu1q8JoY.xc8qe8KFxPFRRyvNrC6P7rO6ytbqgBT5LsoMsnsssswW8UeURywHFwHh8a+1ujlAH2cpm5oFCZPCJoYnKcoKwy8bOm22oPB8du26EssssMlyblSRywC7.OPzst0sjlAH2cFmwYD+4+7eNoYXq1psJdgW3E79NERnoO8oGsoMsIl8rmcRyw8bO2SbHGxgjzLP0a9VnYpewu3Wj7RSi3e+9MLU2ka.Q7O9G+i3Zu1qM0wHdtm647NKARrS6zNsjWZZDQbxm7ImrqjcfHdoW5khAO3Am5XDuvK7BkE6QAxYm9oe5IuzzH92WLGe8W+0oNFP15UdkWItxq7JScLhwO9wGW8Ue0oNFPV6LNiyH4klFw+taixge+Bp9RwoYnm64dtXDiXDoNFQDQLkoLk3FuwaL0w.xVm24cdwhW7hScLhHh3BuvKLYOR.gb23F23hG3AdfTGiHhHdm24cbgT.Iz4e9meYydCF3.GnKjBHQF+3Gebu268l5XDQDw69tuqKjBHgtfK3BhEsnEk5XDQDwEcQWTYwMBBjidkW4UhgO7gm5XDQDwG7AePxe54Q0aJNMCcgW3El5HrLt3K9hiEtvEl5X.YmwMtwEOxi7HoNFK068duWbS2zMk5X.Yoxw8F3IRAT5M9wO93ge3GN0wXol9zmtKjBHQF3.GXpivx3O7G9CtHKgD3UdkWor4BrLhH9vO7Ciq65ttTGCHKMvANvxpWKg+w+3ezSjBJZTbZl4se62NF8nGcpiwxXZSaZkM2ArPNob3wv22T4Xlfp6l1zlVLxQNxTGikw6+9ue7fO3Cl5X.YmxwG+c1a.T5UN9uC+u9W+q39u+6O0w.xNW8Ue0kUEkDg8F.oP43+N7G8QeTYySGCp9QwoYla3FtgxtM7DQDW+0e8oNBPVYVyZVwccW2Upiwx4UdkWIF23FWpiAjUtwa7FKadrb9eydCfRq4Lm4D24cdmoNFKmW60ds34e9mO0w.xJ2zMcS1a.P7Ue0WE29se6oNFKm23Mdi3YdlmI0w.xJCcnCsr7IFo8FPwhhSyL28ce2oNBqP+0+5esr3EKMjKF0nFUY6KQ8x00ofpqJWOm6wdrGKl4LmYpiAjMF8nGcLm4LmTGiUnxk2kRPtnbcuAiYLiI9rO6yRcLfrwi9nOZLqYMqTGiUH6M.JsJW2avS8TOULiYLiTGCpFphkTNd6GVEVEUTwx7eWN8+deq25shV0pVk5X7s5dtm6INjC4PRcLfrvwbLGSbq25sl5XrB0t10tXhSbhoNFPVXpScpQKaYKScL9VMrgMr3vO7CO0w.xB8rm8LF5PGZA4XMs1s8EjiC...TdpEuV4wSEla9lu43XO1iM0wfpYbGmlQFyXFSpivJU4d9fpSJmOe60dsWK93O9iScLfrP47ZAQT9mOn5DmuA...U036wPwfhSyHk6u2.K2yGTcwzm9zioO8om5XrRY8.nznb+bsx87AUW7we7GGu669toNF....eu32MfhAEmlQlvDlPpivJ0K+xubr3Eu3TGCnZux80BhHhW5kdoTGAHKTtudvq9puZrnEsnTGCnZux80B....VQd8W+0iu9q+5TGCplQwoYjoN0ol5HrRMu4Mu3e8u9WoNFP0dk6qEDQUiLBUGTtet1BVvBh2+8e+TGCnZux80B....VQV7hWrmdNTvo3zLwblybhO6y9rTGiuSVjCJ9l1zlVpiv2IqE.Eee8W+0UIdeBa8.n3qpvdC....VQ78YnPSwoYhYNyYl5HrJ4K9huH0Q.p1qpv5AVK.J9pJrVPDVO.JEpprd....v2je2.JzTbZl3q9puJ0QXURUkbBUk8ke4Wl5H7cxZAPwWUg0Bhv5APoPUk0C....9l76FPglhSyDKdwKN0QXURUkbBUksjkrjTGguSVK.J9pJrVPDUcxITUlyy...fpp78YnPSwoYh0ZsVqTGgUI0st0M0Q.p1qpv5AVK.J9pJrVPDUcxITUlyy...fpp78YnPSwoYhFzfFj5HrJo90u9oNBP0dUEVOvZAPwWUg0Bhv5APoPUk0C....9l78YnPSwoYhF1vFVk3Gdbi23MN0Q.p1ai1nMJ0Q36j0Bfhu5V25FMtwMN0w36j0CfhupB6M....XEw2mgBMEmlQ1jMYSRcDVopYMqYz7l27TGCnZux80BhHhVzhVj5H.Ygx80CprxJ8EffRfx80B....9132QjBMEmlQ5XG6XpivJUaaaaiZVyZl5X.U6UtuVPDQzoN0oTGAHKTtudPaZSahZW6Zm5X.U6UtuV....vJRKaYKi5Uu5k5XP0LJNMirsa61l5HrRUtmOn5hV1xVFMoIMI0wXkx5APoQ494Zk64CptXi23MNV20ccScL....9dwua.ECJNMirK6xtj5HrRsy67Nm5H.Yix4y2ZQKZg2ogPIh8F.7+obe8....fuI+tATLn3zLRm6bmKaeGhVYkUF669tuoNFP1X+2+8O0Q3a0Ab.GPpi.jMZe6aeY66BjJpnhX+1u8K0w.xFky6M....XEwuiHECJNMy7S+o+zTGgUnt10tFMsoMM0w.xFG3AdfksuSgO3C9fScDfrR454b6vNrCw5u9qepiAjM1+8e+8NEF...pxXq1psxSsNJJpXIKYIKI0gn5jJpnhk4+tb6+8NgILg3G8i9QoNFKma9lu43XO1iM0w.xJGxgbHw8ce2WpiwxXS2zMMlxTlxxsVJPwyq9puZzwN1wTGikyMbC2Pzqd0qTGCHqb3G9gGCe3CO0wXYrwa7FGScpSMprRWyuPoxjm7ji1111l5Xrbtlq4Zh9zm9j5X.YkdzidD24cdmoNFKil27lGSaZSKpQMpQpiBjMdq25shV0pVk5Xrbtpq5phS5jNoTGCpFx29Lyz4N24nKcoKoNFKilzjlDcu6cO0w.xNm3IdhoNBKm9zm9nzTnDqCcnCwNti6XpiwxnQMpQwQbDGQpiAjcJG2aPu6cuUZJThska4VV189BqAMnAQO5QORcLfrSe6aeScDVNmvIbBJMEJw1hsXKhexO4mj5XrLpe8qe7y9Y+rTGCplx2.MCcdm24k5HrL5e+6eTm5TmTGCH6r268dGa61tsoNFKUiabicUhAIR41dCNiy3Lh5V25l5X.Ymce228XG1gcH0wXoZXCaXbJmxo7+m8t2i6qmu+ef+7pt5vU5bgNpLVMJkUNDcvoPRkbXiZrkY7cCKGmCaNFy4uQNLGx1x7kkhZ9hBIjCIaTnHTTQQngRrIccc86O7a8UqnV974y6OWWute++Je50yGqa686qW84w6CYcLfjz4bNmSVGg0xIcRmTzfFzfrNFPxYO1i8H5Uu5UVGi0nAMnAwvG9vy5X.Iohs8Fbhm3IFMpQMJqiAUSo3zDz.Fv.JZtqS27Meyie4u7Wl0w.RViXDiHqivZb5m9oGMrgMLqiAjj5W+5WQSYIMqYMKNoS5jx5X.Iqho8Fbpm5oFMtwMNqiAjj128ceid26dm0wHh3Ku.KOkS4Tx5X.Iqho8FbJmxoDMsoMMqiAjj1q8Zuh8Zu1qrNFQDe4EX4ocZmVVGCpFSwoIpa3FtghhG4UW0UcUtpQgLT+5W+hAO3Am0wH5PG5fM7.Yre2u62UT7Hu5JthqvUMJjg5ae6abXG1gk0wH1lsYahy3LNirNFPR6FtgaHJszRy5XDW1kcYQSZRSx5X.Iq8Zu1q3HNhiHqiQr0a8VGm0YcVYcLfj10e8WeTqZUqrNFwkbIWRzrl0rrNFTMV12bFYhcZm1oL+QaQe6aeie7O9GmoY.Hhq65ttLsjhZTiZD27MeyQcpScxrL.7kuGzy56li8bO2y3nO5iNSy.PDiZTiJSKonjRJItoa5lh5V25lYY.3KeOne5m9omoYn28t2wwdrGallAfHt5q9pyz6zyRJoj3Fuwazq5KHis8a+1Gm4YdlYZF1sca2JJe+KS0KkTYkUVYVGhpSJojRVqecw7e8tpUspnm8rmwy8bOWAe1snEsHl0rlUzhVzhB9rAVW+k+xeIN3C9fyjYedm24EW3EdgYxrAVaewW7EQu6cuim8Ye1B9r2hsXKhYMqYEspUspfOaf008ce2WbPGzAkI+6Y90+5ec7a+s+1B9bAVWqd0qN1i8XOhoO8oWvmcyadyiYMqYEsoMsofOaf00jm7jiC7.OvLYuAmwYbFwke4WdAet.qqUu5UG68du2wS9jOYAe1MqYMKl4LmYrUa0VUvmMoE2woIrZW6ZGie7iO1xsbKKnysN0oNw3F23TZJTDYvCdvwYe1mcAet8u+8ON+y+7K3yEX8qV0pVw3G+3iV1xVVPmasqcsi65ttKklBEQF3.GXbNmy4Tvm69u+6eQ06RMH0UZokFiabiKZcqacAct0pV0JF6XGqRSghHGvAb.wEbAWPAet8su80ETETDozRKMtq65th1111VPmaspUsh67NuSklRAghSSbsu8sOd3G9gKXOJt9WmXs28t2Ej4Arw6RtjKof9XvpW8pWwce22cQw6aYf+OssssMlxTlRA6QwUMqYMi+7e9OG64dtmEj4ArwaDiXDEzGCV69tu6wDlvDJJdeKC7+o0st0wTlxThl27lWPlWMpQMh63NtiXe1m8ofLOfMdm24cdwIdhmXAad65ttqwDm3DKJdeKC7+oksrkwTlxThMey27Bx7pQMpQ7m9S+oX+1u8qfLOv2VMQW5RWhG4Qdj79c.ZYkUVLtwMt3fNnCJuNGfMc2zMcSwwe7GedeN8su8MdfG3A79IAJR0oN0oXpScp486.z5V25FicriMNjC4PxqyAXS2MbC2PL7gO779b168duiIMoIE0qd0KuOKf+ysca21EScpSMueGfVm5Tm3Nuy6L9A+fePdcN.a5t1q8ZiS4TNk79b1i8XOhG7Aevn90u948YA7etN1wNFO5i9n4867zZW6ZG29se6wQbDGQdcNvWkhSIhHht0stEyXFyH1wcbGyKqeqacqiG6wdrL6cnHvFmZTiZD2vMbCwHG4HiZUqZkWlwwcbGWLoIMongMrg4k0GH2XG2wcLlwLlQzst0s7x52xV1xXpScpwgcXGVdY8AxMpQMpQLpQMpXTiZT4s8FbLGywDO3C9fQiZTixKqOPtQW5RWhYLiYD6zNsS4k0uEsnEwi7HORb3G9gmWVefbiRJojXjibjw0e8WeT6ZW67xLF1vFV7vO7CGMtwMNur9.4FctycNlwLlQrq65tlWV+sXK1h3ge3GNF5PGZdY8guNJNk0ncsqcwy9rOabFmwYjSe7Xc3G9gGyd1yNucBTfbuS4TNk3YdlmI1tsa6xYq4lu4adLgILg3lu4aNu8EuBja01111XFyXFwYcVmUNcuAG1gcXwrm8rice228b1ZBjeM7gO73Ye1mM5Tm5TNaMadyadL9wO93Vu0a0dCfpHZcqacL8oO8327a9M4zGclGxgbHwrm8rid0qdkyVSf7qS3DNg3u9W+qQm6bmyYqYSaZSi65ttq3O9G+i4sRYAxsZUqZU7TO0SEm24cd4z8zePGzAEyYNyI1i8XOxYqIrwRworVpcsqcb4W9kGuzK8Rw.G3.+VsV6xtrKwi8XOVL1wN1B16PUfbmt28tGu3K9hw0ccWWrEawVrIuN0qd0KNqy5rh4Mu44tNGpBpV0pVwkdoWZLm4Lm3fNnCJJojR1jWqcZm1oXpScpw3G+3il0rlkCSIPgv2+6+8iW3Edg3Ftga3a0q4ixJqr3LNiyHl27lm65bnJnZUqZEW7EewwblybhC9fO3uU6MnacqawTlxTh64dtmB16PUfbmt10tFyZVyJtwa7FiV1xVtIuNkUVYwoe5mdL+4O+3G9C+g4vDBTHTZokFW3EdgwK+xubbnG5g9sZuA63NtiwC8POT7W9K+kB16PU3eWIUVYkUl0gn5j+8SJTU+ude0W8Uia9lu4XhSbhwhVzh1fe9l27lGG3AdfwwcbGm6hDnZjO+y+73tu66Ntsa61hoMsoEqZUq5a7yWRIkD67NuywPFxPhgMrg4wqCTMxq+5udbS2zMESbhSLV3BW3F7y2rl0r0r2fd1ydl+CHPAwpV0ph64dtmXLiYLwzl1zhO+y+7uwOeIkTRz8t28XnCcnwvF1vbgUBUiLu4Mu3lu4aNlvDlPrfErfM3muoMsoQ+6e+ii63Ntn28t2EfDBTH7EewWrl8F73O9iuQs2ft0stECYHCIN5i9nil1zlVfRJP917m+7WydCdy27M2fe9lzjlD8u+8ON1i8XcGlRQAEmliUcq3zupW8Ue0Xlyblwbm6biksrkEqbkqLJqrxhlzjlDcricL5ZW6Z78+9e+nF0vMxLTc1JW4JiYLiYDyYNyIV3BWXrhUrhn7xKOZXCaXz5V25nyctywttq6pqJLHA7pu5qFyZVyJdkW4UVm8FzgNzgnqcsqQ25V2r2.nZtO8S+z0ZuAKe4KeM6MnUspUqYuAeadBV.T0vq8Zu1Z9dC9fO3CVydCZbiabzwN1wnKcoKQ25V2xouB..J97Ye1msl8FrfErf0YuAcpScJ10ccWisbK2xrNp.4Yu9q+5wLm4LiW4Udk0YuAcnCcH5RW5Rz8t2c6MfhJJNMGq5bwo........P0Ut7+A........RdJNE........H4o3T........fjmhSA........RdJNE........H4o3T........fjmhSA........RdJNE........H4o3T........fjmhSA........RdJNE........H4o3T........fjmhSA........RdJNE........H4o3T........fjmhSA........RdJNE........H4o3T........fjmhSA........RdJNE........H4o3T........fjmhSA........RdJNE........H4o3T........fjmhSA........RdJNE........H4o3T........fjmhSA........RdJNE........H4o3T........fjmhSA........RdJNE........H4o3T........fjmhSA........RdJNE........H4o3T........fjmhSA........RdJNE........H4o3T........fjmhSA........RdJNE........H4o3T........fjmhSA........RdJNE........H4o3T........fjmhSA........RdJNE........H4o3T........fjmhSA........RdJNE........H4o3T........fjmhSA........RdJNE........H4o3T........fjmhSA........RdJNE........H4o3T........fjmhSA........RdJNE........H4o3T........fjmhSA........RdJNE........H4o3T........fjmhSA........RdJNE........H4o3T........fjmhSA........RdJNE........H4o3T........fjmhSA........RdJNE........H4o3T........fjmhSA........RdJNE........H4o3T........fjmhSA........RdJNE........H4o3T........fjmhSA........RdJNE........H4o3T........fjmhSA........RdJNE........H4o3T........fjmhSA........RdJNE........H4o3T........fjmhSA........RdJNE........H4o3T........fjmhSA........RdJNE........H4o3T........fjmhSA........RdJNE........H4o3T........fjmhSA........RdJNE........H4o3T........fjmhSA........RdJNE........H4o3T........fjmhSA........RdJNE........H4o3T........fjmhSA........RdJNE........H4o3T........fjmhSA........RdJNE........H4o3T........fjmhSA........RdJNE........H4o3T........fjmhSA........RdJNE........H4o3T........fjmhSA........RdJNE........H4o3T........fjmhSA........RdJNE........H4o3T........fjmhSA........RdJNE........H4o3T........fjmhSA........RdJNE........H4o3T........fjmhSA........RdJNE........H4o3T........fjmhSA........RdJNE........H4o3T........fjmhSA........RdJNE........H4o3T........fjmhSA........RdJNE........H4o3T........fjmhSA........RdJNE........H4o3T........fjmhSA........RdJNE........H4o3T........fjmhSA........Rdkl0AfpNdq25shYMqYEyctyMV1xVVrxUtxnrxJKZRSZRzwN1wnqcsqw26688x5XBjmspUspXlyblwblybhErfEDqXEqHJu7xiF0nFEspUsJ5bm6bz8t28ngMrgYcTAxyd629siYMqYEuxq7Jq28FzktzkX61tsKqiIPd1WcuAKbgKLV9xWdTd4kGMrgMLZcqaczoN0oXm1ocxdCfDvhW7hiYNyYFyctyM9fO3CVq8FzgNzgnKcoKw1u8aeVGSf7ru3K9h056M3qt2fu52aPiZTix5nBjmsjkrjXlyblq46M3S9jOIJqrxhF23Ful8FzoN0orNlvZQwo7MZQKZQwnG8niINwIFuxq7JavOeaaaaiANvAFG2wcbQW6ZWK.IDnPn7xKOtu669ha61ts3QdjGIV4JW423muV0pVQu5UuhgNzgFCcnCMpW8pWAJo.4au8a+1wsbK2RLwINw3ke4WdC94aSaZyZ1avNti6XAHg.EBkWd4wC7.OPLlwLlXJSYJav8FTZokF8pW8JFxPFR7idvZkrC...H.jDQAQ0Q+nXy1rMq.kTf7sEu3EGidziNlvDlPLm4LmM3mu0st0w.G3.ii8XO1nacqaEfDBTHTQEUrV6M3S9jO4a7yWZokF8rm8LNhi3Hhi7HOxn90u9EnjBjusjkrj0r2fYO6YuA+7spUsJFv.FPbrG6wF6zNsSEfDBeyJoxJqrxrNDUmTRIkrV+5pp+06a9luY7a9M+lXbiabQEUTwlzZrW60dEW1kcYwtrK6RNNc.EJUTQEwsca2VbAWvEDu0a8VaRqQiabiiS6zNs3TO0SUApPUXKbgKL9M+leSbW20cEkWd4aRqwdrG6QbYW1kE8nG8HGmNfBkJpnh31u8aON+y+7iEsnEsIsFMpQMJN0S8TiS6zNMEnBUgsnEsn3bNmyI9y+4+7l7dC5cu6cb4W9kG61tsa43zATnTYkUF2wcbGw4cdmWrfErfMo0ngMrgwobJmRb5m9oq.UnJr29se63bNmyIty67NiUu5UuIsF8rm8Lt7K+xid1ydliSGrwSwo4XU0KNs7xKO9s+1ea7a+s+1XUqZUeqWuRJoj3nO5iNtlq4ZhFzfFjCRHPgxK+xubbTG0QEyZVyJmrdst0sN98+9eer+6+9mSVOfBixKu73xtrKKFwHFQNYuAQDwvF1vhQMpQ4w1ITEybm6bii5nNp34e9mOmrdspUsJt0a8ViC3.Nfbx5ATXTQEUDW9ke4wEdgWX74e9mmSVyi5nNp35ttqyisSnJlW8Ue03G+i+wwe6u82xIqWKZQKhQO5QGCX.CHmrd.EFUTQEwUcUWUb9m+4G+y+4+LmrlCcnCMtga3FhF23FmSVO3+DJNMGqpbwou669twgbHGRLiYLib9Zu0a8VGSXBSvinOnJha4Vtk3jNoSJmsYm+kRJoj3jO4SNtxq7JiZVyZlSWafbu268du3POzCMd5m9oy4qc6ae6i64dtGOh9fpH98+9eebhm3Ily2aPDQL7gO7Xjibj1a.TEv6+9uebXG1gEO4S9j470dq1psJtm64d7H5CphXLiYLwwe7Ge7O9G+ib9ZeBmvIDWy0bMQok5sLGTraYKaYwgcXGVLsoMsb9Z2l1zl3tu66N10ccWy4qM7MQwo4XUUKN8ke4WN5e+6+l7ihyMFMnAMHF23FWzu90u71L.91oxJqLNyy7Liq7Jux75bF3.GXL1wNVO5dghXyctyM5e+6ervEtv71L1rMayhwMtwE8u+8OuMCfu890+5ecboW5klWmQ+6e+iwMtw4Q2KTD60dsWKNfC3.1jeTbtwnd0qdwXG6XiANvAl2lAv2dm64dtwEewWbdcF8qe8KF+3GuGcuPQr4Mu4EGvAb.wa7FuQdaFkUVYwcdm2YL3AO371Lf+cJNMGqpXwou5q9pQe5SehO3C9f79rpcsqcbe228E629se48YA7etS9jO4XTiZTEjY0291239u+6OpScpSAYd.a7l27lWzqd0q38e+2OuOqZUqZE268dudTcBEoNsS6zhQNxQVPl0dsW6ULoIMont0stEj4Arw6Mdi2H5Uu5Urzktz79rJszRiILgIn7TnH0YdlmYbEWwUTPlUe5SehG7AevnrxJqfLOfMdKXAKH5Uu5U7Nuy6j2mUMqYMi69tuakmRAihSywppUb5RVxRhdzidDKdwKtfMy5Uu5EO1i8XwtrK6RAal.aXW7Eeww4dtmaAclG5gdnw3G+3WmycBjcd228cidzidjWeJT7uqrxJKl5TmZra61tUvlIvF1kcYWVb1m8YWPm4AcPGTLwINQ6M.Jh7du26E8nG8Hu9Tn3eWcqacioLkoD8pW8pfMSfMrq5ptp3W8q9UEzYNfALf3du26MpQMpQAct.e89fO3ChdzidDu4a9lErYVm5Tm3gdnGJ1i8XOJXyjzkhSywpJUb5pW8pi8bO2y7x6srMj1111FyblyLZdyadAe1.qqIO4IGG3AdfYx4rtjK4RJ3eor.qekWd4wdu26c7DOwSTvmcqZUqhW3EdgXy27MufOaf00TlxTh90u9EUTQEE7YOhQLhB9EyEv5W4kWdru669FO1i8XE7Y2hVzh3EdgWH1xsbKK3yFXc8nO5iF669tuYxdCN+y+7iK3BtfB9bAVWUTQEw9u+6e7HOxiTvm8VtkaYLqYMqnksrkE7YSZwkpSB6bO2yMSJMMhHd629sigMrgkIyFXsszktz3nNpiJytPON2y8bioO8omIyFXscAWvEjIklFQDuy67NwQcTGUlLaf016+9ueLzgNzL4KFMhu7bQO4S9jYxrAVaW7EewYRooQ7k+6T9Q+neTlLaf01xV1xhgLjgjY6M3htnKJyNWDvZ6RuzKMSJMMhu7ofwPG5PKpuY0n5A2wo4XUUtiSeoW5kht28tGqd0qNSywXG6XiC+vO7LMCPp6HNhiHtq65txzLzoN0oXVyZVQspUsxzb.orW9ke436+8+9wW7EeQlli+m+m+GeIoPF6HOxiLti63NxzL789deu3EewWLpcsqcllCHk8pu5qFcsqcMV0pVUlliwLlwD+jexOISy.j5F1vFVba21skoY369c+twrm8ri5Tm5jo4.RYu9q+5QW5RWhO+y+7LMG25sdqwwbLGSllApdycbZh53O9iOyKMMhHN4S9jiO8S+zrNFPx5QezGMyKMMhurvlQMpQk0w.RZmvIbBYdooQDwodpmZrxUtxrNFPxZZSaZYdooQ7kE1b0W8Um0w.RZm3IdhYdooQDwoe5mdrhUrhrNFPx5oe5mNyKMMhHl27lWbUW0Uk0w.RZCe3COyKMMhHNiy3LhO9i+3rNFTMlhSSPOzC8PY1in2+cKcoKMtwa7Fy5X.Iqho2eXW9ke4tPJfLxTm5TioMsok0wHh3KeDgd8W+0m0w.RVm24cdYcDViq3Jth3S9jOIqiAjjl1zlVL0oN0rNFQDe4iHzq8Zu1rNFPxpXZuAW0UcUwxW9xy5X.Iom9oe53gdnGJqiQDQDe3G9gw0bMWSVGCpFSwoInK5htnrNBqkq7JuxhhqTEH07nO5iVT8tEcYKaYwMcS2TVGCHIUrs2fq5ptp3e7O9GYcLfjyS7DOQl8dNd84C+vOL9c+teWVGCHIUrs2fQNxQ5hrDx.Se5SOdzG8Qy5XrFe7G+wtHKgLRw1dCtlq4ZbQVRdihSSLyYNyon4tM8e48e+2Otm64dx5X.ImhwRJuoa5lJZe2PCUWM24N2hl61z+k+9e+uGie7iOqiAjbJF2avMey2r8F.EXyadyqn4tM8e4i9nOJF23FWVGCH4TLt2fa4VtknhJpHqiAjTdy27MiG9ge3rNFqkku7kGicriMqiAUSo3zDyu+2+6y5HrdUrlKn5pksrkE268duYcLVGye9yun5NcARAEq+L3h0bAUW8QezGESXBSHqiw5XAKXAEU2oKPJnX8mAeq25sl0Q.RJKe4KOt669ty5XrNdq25shoLkoj0w.RJ+g+venn7hYzdCHeQwoIlhwuLjH9x2eJe3G9gYcLfjwC7.OPrpUsprNFqWEqmmBptZhSbhYcDVudpm5ohO3C9frNFPx3AdfGnn80mg8F.EVEqGy8LOyyDKcoKMqiAjLl7jmbQ6qOih0ySAUWUrdL2e8u9Wikrjkj0wfpgTbZBY1yd1wa8VuUVGi0qxKu7XxSdxYcLfjw8e+2eVGguVEyYCptYtyctwa9luYVGi0qJpnhXRSZRYcLfjwC7.OPVGguVEyYCptYdyadw7l27x5XrdUYkUZuAPATw7O+sXNaP0MKXAKHl6bmaVGiuVNe.4Ckl0AfBmG+we7rNBeiNxi7Hii7HOxrNF.Yr27MeyXwKdwQaZSax5n.U6Uru2foMsoE+jexOIqiAjDJlOevhVzhhRJojrNF.EAd7G+wie5O8ml0w.RBEy6MXIKYI1a.PDwWdtpi63NtrNFTMi63zDxy8bOWVGA.1n729a+srNBPRnXeuANW.TXr3EuXO9KApRvdCfBiktzkFKdwKNqiA.aP1a.4CJNMg7hu3Kl0Q.fMJNeETX7BuvKj0Q3azbm6biu3K9hrNFP0d94t.UU7Zu1qE+y+4+LqiATsm8F.TUwa7FuQ7oe5ml0wfpYTbZBYgKbgYcD.XihyWAEFE6GqUd4kGu8a+1YcLfp8J1OW..+KUVYkwa8VuUVGCnZO6M.nphJqrxXQKZQYcLnZFEmlHVwJVQr7ku7rNF.rQwWFBj+8Ye1mEe3G9gYcL1fb9.H+yEn.PUINmEj+43LfpRbNKx0TbZhXEqXEYcD.XilyYA4eUUNNqpRNgpxbbFPUItnvg7OGmATUhyYQtlhSSDdNeCTUxm8YeVVGAnZupJ6Mv4Cf7upJmO.fHr2.nPvwY.Uk3bVjqo3zDQIkTRVGA.1n4bVP9WUkiyppjSnpLGmATUhyYA4eNNCnpDmyhbMEmlHpW8pWVGA.1n4bVP9WUkiyppjSnpLGmATUhyYA4eNNCnpDmyhbMEmlHZTiZTVGA.1n4bVP9WUkiyppjSnpLGmATUhyYA4eNNCnpDmyhbMEmlHZPCZPzjlzjrNF.rQYq1psJqi.TsWYkUVr4a9lm0wXCx4Cf7OGmATUhyYA4eNNCnpDmyhbMEmlPZe6aeVGA.1nr0a8Vm0Q.RBE66MnzRKMZSaZSVGCnZO+bWfpJpYMqoubTn.vdC.ppnjRJIZW6ZWVGCplQwoIjcbG2wrNB.rQw4qfBih8i05bm6bTZokl0w.p1qX+bA.7urca21E0t10NqiATsm8F.TUQG6XGixJqrrNFTMiuIpDxNuy6b7G+i+wrNFes94+7edbi23Ml0w.RBsrksLV5RWZVGiuV6zNsSYcDfjvNuy6bL5QO5rNFesbt.nvnEsnEQaZSahEu3Em0Q4q0a+1us6.cn.3O9G+iwO8m9Sy5X70Zm24cNqi.jDZdyadz9129XgKbgYcT9ZsfErfh9mfNP0A29se6wO9G+iy5X70xdCHevcbZBYu1q8Jqiv2nh87AUmTLe7VG6XGiV1xVl0w.RBEymKHhh+7AUmTLe711rMaiRSgBjh4yEDQwe9fpSJlOdq8su8JMEJP1y8bOy5H7MpX9bUT0khSSHeuu22K1lsYax5XrdUZokF6+9u+YcLfjw.Fv.x5H70pXNaP0Ma61tsQG5PGx5XrdUyZVyne8qeYcLfjwAdfGXVGguV1a.T3z9129X629sOqiw5UMpQMhC3.NfrNFPxnXduAEyYCptossssQW5RWx5XrdURIkD8u+8OqiAUCo3zDygdnGZVGg0q9129FMpQMJqiAjL5e+6eT25V2rNFqWEqmmBpt5vNrCKqiv50dsW6Uzzl1zrNFPx3.NfCHpW8pWVGi0K6M.JrJV2aPe5Sehl27lm0w.RF6+9u+Q8qe8y5XrdYuAPgUw5dC5Uu5Urka4Vl0wfpgTbZh4XNliIqiv50O6m8yx5H.IkF23FWTtomse629X21scKqiAjT9o+zeZTRIkj0wXcXuAPgUCaXCievO3Gj0wXczwN1wn28t2YcLfjxQezGcTiZT780EYuAPgU8qe8iC+vO7rNFqisYa1lh9GcnP0MCaXCqnbuAEqccPUeEe++1IupCcnCw9rO6SVGi0RqacqiAMnAk0w.RN+hewuHqiv5nXLSP0cay1rMw9se6WVGi0RKZQKhC9fO3rNFPx43O9iOqiv5vdCfBu1291Wz8HwcK1hsvcXFjAJF+4v+hewunn7B+DpNqssssw.G3.y5XrVZdyadQ4E9IUOn3zDz4cdmWVGg0xYcVmUTqZUqrNFPxY228cun5BonksrktJxgLx4dtmaVGg0xYdlmYT6ZW6rNFPxYW1kcon5BoXK2xsLNti63x5X.Iohs8F7q9U+ph1W0HP0Ycu6cun58G3lu4ad7y+4+7rNFPRpXauAm1ocZEsupQnpOEmlf5Se5Sz2912rNFQDQzt10t3XO1iMqiAjrFwHFQQyUp44bNmiuLDHizyd1yne8qeYcLhHhnMsoMw+0+0+UVGCHYcQWzEUzr2fe8u9WGkUVYYcLfjzttq6ZLfALfrNFQDQzpV0phx6HdHULhQLhhlGQmm0YcVwlsYaVVGCHI08t28XvCdvYcLhH9xmRUm3IdhYcLnZrhiepGEb2vMbCQcpScx5XDW20ccEE4.RU69tu6wQezGcVGin6cu6tpQgL10ccWWQwEuv0dsWqhRfLztrK6RQwE13Nti6XbBmvIj0w.RZEK+L4q4ZtF2QIPFp6cu6EEWXi6vNrCwvG9vy5X.Isq4ZtlhhKdgQNxQF0u90OqiAUio3zDUG5PGx7au9e3O7GVz8rQGRQWwUbEQKaYKyr4W6ZW6XzidzEMWAqPpZa21sMN+y+7yzLbHGxg3caJTD3xtrKKZcqaclM+ZUqZEidziNpYMqYlkAfH15sdqiQLhQjoYXPCZPd+kAEAtzK8Ri1111lYyuzRKMF8nGcTZoklYY.3Ke5QdwW7EmoY3.OvCLFxPFRllAp9qjJqrxJy5PTcx+9i0ph4+5shJpH5W+5WLkoLkB9r21scaim+4e9ngMrgE7YCrtdhm3Ih8du26n7xKufO6q65tNOdMfhDUVYkwAdfGXL4IO4B9r+NemuS77O+yGMtwMtfOaf00S+zOcrm64dFqd0qtfO6q9pu53jO4StfOWf0UkUVYLnAMn39u+6ufO610t1EyZVyJZRSZRAe1.qqYLiYD8oO8I9hu3KJ3y9JuxqLN8S+zK3yEX8avCdvw8du2aAetssssMl0rlUzrl0rB9rIs316IgUiZTi3Nuy6L9te2uaActMtwMNlvDlfRSghH8oO8IF4HGYAetCaXCSooPQjRJoj31u8aO5XG6XActMrgMLlvDlfRSghH8rm8LF0nFUAetG0QcTJMEJhTRIkD+o+zeJ1tsa6JnysAMnAwDlvDTZJTDoG8nGw0e8WeAetCYHCQooPQlwLlwDcpScpfNy5W+5G2y8bOJMkBBEml3ZdyadLkoLknMsoMEj4Uu5Uu39u+6O1gcXGJHyCXi2vG9viy67NuB17F7fGbbq25sVvlGvFml0rlESYJSI1psZqJHyqrxJKtu669ht10tVPlGvFui+3O9B5ioyANvAF+g+venfMOfMNMoIMIlxTlRz9129Bx7pacqa7+9+9+FcqacqfLOfMdG2wcbwkbIWRAad8u+8Otsa61JXyCXiSiabiioLkoDemuy2ofLu5Tm5D+k+xeI14cdmKHyCTbJQ6ZW6hoMsok2u6RZVyZV7vO7CG8rm8LuNGfMcW3EdgwkbIWx57XGOW6HOxiLtq65t7tKCJR01111XZSaZ486tjl1zlFOzC8PQe5SexqyAXS24dtmab4W9km22avPFxPhwO9w6cWFTjp0st0wzl1zx62cIMtwMNl7jmbrm64dlWmCvlty9rO63+9+9+NpQMxuesx+ve3OLtm64dhZUqZkWmCvllV1xVFSaZSKueCR0nF0n3AdfGH1m8YexqyA9pTbJQDe46UroO8oG629se4k0uyctywy7LOiRSgp.N6y9ri+7e9OGMnAMHmu10rl0LFwHFQb629sG0t10Nmu9.4Nsu8sOl9zmdb.GvAjWV+N0oNESe5SO5cu6cdY8AxcNiy3LhwMtwEMpQMJmu10rl0LN+y+7i63NtinN0oN470GH2Yq1psJd5m9oiALfAjWV+sa61tX5Se5JMEpB3TO0SMt669tyKupMpQMpQbNmy4DicriMpacqaNe8AxcZSaZS7TO0SECZPCJur9cricLd5m9oUZJEbJNk0noMsowC9fOXbsW60F0u90OmrlkVZowocZmV7bO2yUveWpBro6vO7COdoW5kxoeoEcricLdxm7Iiy8bO2b1ZBje03F23XRSZRw0e8WeN6honl0rlwIexmb7bO2yUveWpBro6vNrCKdwW7Ei8du26b1Z9c+te2XZSaZwEbAWPd+NZEH2nQMpQw8ce2Wbi23MFMrgMLmrl0rl0LF9vGd77O+yWveWpBro6fO3CNdoW5kh9129lyVysYa1l3we7GOtnK5hr2.nJhF1vFF268duwsbK2RN6BsrF0nFwIbBmPLyYNyB96RUHBEmx+lRJoj3W9K+kw7m+7iewu3WrIekcUiZTi3fO3CNl8rmcbUW0U4pGGpBp8su8wi8XOVLwINwnyctyaxqSqZUqhq+5u9XNyYNwtsa6VNLg.EJmvIbBw7m+7iS3DNguU6M3fNnCJdoW5khq9puZW83PUPsqcsKl5TmZbu2689s5QxUKaYKiq8Zu13ke4W1SjFnJpe9O+mGye9yO9k+xeYTVYksIsFkTRIwfFzfhW7EewXTiZTaxqCP1osssswTlxTh669tunqcsqaxqSKZQKhq9pu53UdkWwSjFnJpi8XO1X9ye9wIcRmTTu5UuMo0njRJIFv.FP7BuvKDW+0e8axqC7sUIUVYkUl0gn5j+8qFpp5+06e+u+2iwLlwDSXBSHd1m8YixKu7uwO+NrC6PLnAMn3m8y9YQ6ae6KLgDnfXZSaZwXFyXhIO4IGu268deie1FzfFD669tuwPFxPhAO3A68UFTMxG9ge3Z1avLlwL1f6MnyctywfFzfhi4XNl367c9NEnTBTH7DOwSD21scawjlzjhktzk9M9YaPCZPrO6y9DCcnCMF7fGr2WYP0HezG8Qwsca2VLgILgX5Se5av8FzoN0oXfCbfwO6m8yhsYa1lBTJAJDdpm5ohwLlwDSZRSJd228c+F+r0u90O1m8YehgLjgDGxgbH1a.TMxG+we7Zs2fUu5U+M9429se6WydC11scaKPoD95o3zbrpaEm9U8we7GGuzK8Rwq7JuR72+6+8XkqbkQYkUVzjlzjnicriQW5RWhVzhVj0wDHOqxJqLdsW60h4Lm4DKbgKLVwJVQTd4kGMrgMLZcqacz4N24nScpS9G8.Ifku7kGu3K9hwbm6biksrksV6MnCcnCQW6ZWs2.HATYkUFu9q+5wblybhErfErV6MnUspUqYuAd+lCU+s7ku7078F7U2aPiabiWy2aPKaYKy5XBjmUYkUFyadyaM6MX4Ke4q0dC5Tm5Tz4N2Y6M.R.qXEqXM6M3C9fOHV4JWYT25V2078FzktzknUspUYcLg0hhSywpNWbJ........Tck2wo.........IOEmB........j7TbJ........PxSwo.........IOEmB........j7TbJ........PxSwo.........IOEmB........j7TbJ........PxSwo.........IOEmB........j7TbJ........PxSwo.........IOEmB........j7TbJ........PxSwo.........IOEmB.......PAyRVxRhm4YdlrNFv5Pwo........Tv7tu66F69tu6w9u+6uBTonhhSA.......nf6ge3GVApTTQwo........jYTfJEKTbJ........YNEnRVSwo........TzPApjUTbJ........EcTfJEZJNE.......fhVJPkBEEmB.......PQOEnR9VIUVYkUl0gn5fRJojrNB........Ii8a+1u3BtfKH1sca2x5nP0DtiSA.......nJG2Apjqo3T........fjWoYc.........f+S4Q0K4ZJNMGwqJV.......fMrm64dtXm24cdS9OuBSIeQwo........TzSgojuo3T........JZovTJTTbJ........EcTXJEZJNE.......fhFJLkrhhSA.......HyovTxZJNE.......fLiBSoXghSA.......nfSgoTrojJqrxJy5P........PZXIKYIwa8VukBSonihSA........Rd0HqC..........YMEmB........j7TbJ........PxSwo.........IOEmB........j7TbJ........PxSwo.........IOEmB........j7TbJ........PxSwo.........IOEmB........j7TbJ........PxSwo.........IOEmB........j7TbJ........PxSwo.........IOEmB........j7TbJ........PxSwo.........IOEmB........j7TbJ........PxSwo.........IOEmB........j7TbJ........PxSwo.........IOEmB........j7TbJ........PxSwo.........IOEmB........j7TbJ........PxSwo.........IOEmB........j7TbJ........PxSwo.........IOEmB........j7TbJ........PxSwo.........IOEmB........j7TbJ........PxSwo.........IOEmB........j7TbJ........PxSwo.........IOEmB........j7TbJ........PxSwo.........IOEmB........j7TbJ........PxSwo.........IOEmB........j7TbJ........PxSwo.........IOEmB........j7TbJ........PxqzrN.........E6V5RWZr7UrhBxrZ2VsUQcqacWqeuO8y9r3e7YeVzzl1znF0v8EGjOn3T.......fMfmalyLdgW5kJHy5mczGczh++EmVQEUDOvjmb7hyd1QDQzf5W+XvCZPQ61pspfjEHk3RR........nH0e64dt0TZZDQ7IqbkwcOwIFe9m+4YXpfpmTbJ.......PQpErnEsN+d+i+w+Hdu2+8yfz.Uu4Q0K.......vFPcpSch5uYa1F0m8e94edr5Uu5052qrxJKp4F46lzu56vz5W+5ud+LarYAXiWIUVYkUl0g........n5h6eRSZcden9yN5iNZwVtk+GuVe3G8QwueLiYsdz710cXGhAdfG325bBr1bGmB.......TjpoMQ7DubH..jvWIQTPToIw+0wbLwLegWH9rO6yh1sUaUr8a21k0wBpVRwo........EwZXCaXrm8oOYcLfp813dXZC........P0XJNE........H4o3T........fjm2wo........IlO7i9n3sW7hiO9i+33e94edzvFzfXyadyiuyVu0QMpw278c26+9uerj24chOd4KOpnhJhVrkaYzhVzhnoMoIQIkTRNKiKeEqHV3hVT7IexmDe5m9oQMpYMiMqd0KZZSZRz910tnt0st4rYAQn3T.......fhVqd0qNthQNx052a26QOh8rO84q8OycOwIFu97l2Z90coycNFP+6eDQDevxVV73OwSDu1q+5q2+r0ey1rnG65tF8XW1k04+17l+7imZ5SOVx67Nq2+r0t10N18dzinm61t8sp.04+FuQ7XSaZw689u+W6mojRJI9ta61F8a+1ungMnAaxyB9pTbJ.......PQrJpnh05WWYkU9M94KszRWq+Lq7S+zHhurPxIbu2arpUspu1+rq7S+z3QdzGMdu268hAz+9G0rl0LpnhJhGcZSKlwy9reiycUqZUwi+DOQ7Vu8aGCdfCLpW8p2F5+osV9G+y+YLkG4QhWZNyYC9YqrxJiWedyKVza8VQ+128M1gN24+ilEr93cbJ.......P0H0o10ds90qZUqJVx67Nwcc2282XooeUy9ke43Y9+WT5TdzGcCVZ5W0atfED+o67NWmBe+lL+23MhadzidipzzupO+y+73du+6++W6cu9SVedFG.+RdfgxCOpLQT7bF0gB3gZmkT6H0rDSaVOoqys8llr+u1VrKoYIMsQWbwJw1o1Em0Yayl1XIqZTpSq3.4jSjyO6MSB+3j.c5SxyuOedE2Wbe3Bd62be+Kd+idzEz4AyD23T.......fhHYJMY7OObvAi+zINwD2T0pqt5Xq0UWrg0u9XzQGM91N5HZqs1h9u+8Srtyc9yGYqnh3y97OehZ4xkK9AaYKwl13FixKu73ecqaEW+F2H5rqtRr1t5pq3Re4WFO6t10ise6tmdhO3XGKFczQSTeUqZUwOZO6IV6ZVSTypWcL7vCG28+88U8BW7hwHiLxDy8e90ec7YewWDMu28N+9mDLCDbJ.......PQjLkj7AGsyN6bhedmM0T7SekWIJcRgq1XCMD6q4li2+nGMt0su8D0GczQiSzZqSLdKadywu3sdq36Moaz51pu9XrwFK9ficr3pW6ZIN2+x4NWriFaLwYMU4ymONwIOYhPSyjISzxK9hwKzbyQlLYlnd4kWdjKWt3YpqtXGM0T7GO9wiu8N2Iw40TCMDYylcN++CLa7T8B.......TDYIKYIyX8csycFuwq8ZyXPlYylM9YG7fy5Z2xl2b7qN7gSDZ5ijISl3menCEqt5pST+92+9wMZu84rW+6W5Rw2byaln1KefCD+38suDglNUe+ppJ9kG9vQ4kW9D0FZnghy7IexbddvbQvo........E4JszRi82RKy4bVdtbw1qu9Y728RszxbdyQyjISr6ctyoUu6t6dVWyCFXf3iO8oSTqwFZH1yt28b1mOR1JpHdoo72z+3xWN5q+9mWqGlJAmB.......Tj6Y28tib4x8Xm25W+5mVsZW6ZiMtgM7XWaiMzvzp0cO8Lqy+pW8pwvCObhZsru88XOmIqoFabZ0l7SSLrPH3T.......fhbabFBDclTYkUNsZadSaZdu1odqT6s2dm04esqe8DiWdtbQ0S4498wohksrH2T54tt28VP6A7Hy9cpF.......fhBUUUUyq4UwxV1zpshUrh484TYkUlHrzgGYjYct28t2Mw3RKszE02nzo9cY8dBNkEIAmB.......TjakqbkK50N0az4bYoKcoIFO0PMmrGLv.IF2cO8D+0O8SWXM2LvMNkEKOUu........E4JqzE+coKSlLK50lOe9Yr93iO9z99l9+K80e+OQ1WJ94FmB.......vSUkTRIQYkUVLxjdJeKqrxhrUTw248d4Ke4em2CRmDbJ........O0kMa1DeOTWSM0D+529sKfcDocdpdA.......3otpW0pRL9NczQL5niVf5FPvo........T.7L0UWhwiM1Xw2byaVf5FPvo........T.7C25ViLYxjn1IO0ohgFZnEz9bku5qR7j+BKVBNE.......fm5Vdtbw9aokD05s2diOr0Vi74yOu1iyegKDG63GO9cuy6D2n81eBzkjlH3T........JHZ94e9Xc0VahZWos1he+69tw+tyNm00M93iGe7YNSb5yd1HhHd3fCF+g268h+1Eu3Sx1khbkVna.........RmJojRh23Ue032bjiDiM1XST+V291wu8HGI1d80G0VaswZpolXoKcoQe80WbmN5Htzkub7edvCRrW4ymOJYJO8uvBgfSA.......nfo5pqNN3q+5wG1ZqwCGbvIpO93iGWos1hqzVayq84mr+8G684dtmTsIo.BNE.......fBpsussEaZSaJN0G8Qy6fRejbUVY7xG3.w1pu9mPcGoEBNE.......fBtrUTQbn27MiczTSwe9rmM5bN9FmFQDUsxUFM1PCwKzbyQ4kW9SotjhYKIe974KzMA........LY80e+Q6s2dzW+8GCLv.Q974iJqrxnxrYi0st0EqolZJzsHEYDbJ........PpWIE5F.........fBMAmB........j5I3T........fTOAmB........j5I3T........fTOAmB........j5I3T........fTOAmB........j5I3T........fTOAmB........j5I3T........fTOAmB........j5I3T........fTOAmB........j5I3T........fTOAmB........j5I3T........fTOAmB........j5I3T........fTOAmB........j5I3T........fTOAmB........j5I3T........fTOAmB........j5I3T........fTOAmB........j5I3T........fTOAmB........j5I3T........fTOAmB........j5I3T........fTOAmB........j5I3T........fTOAmB........j5I3T........fTOAmB........j58ew7.byZABAB4B....PRE4DQtJDXBB" ],
					"embed" : 1,
					"forceaspect" : 1,
					"id" : "obj-35",
					"maxclass" : "fpic",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "jit_matrix" ],
					"patching_rect" : [ 210.199982, 1285.199951, 487.200012, 247.508027 ],
					"pic" : "continuity.png"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-33",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 11.0, 1236.995239, 889.599976, 36.0 ],
					"style" : "",
					"text" : "To maximize the common notes/instruments between segments, a continuity model is implemented after the independent orchestration. This is an important features of the orchidea toolbox."
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"bubbleside" : 0,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-32",
					"linecount" : 5,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 709.599976, 813.800049, 191.0, 98.0 ],
					"style" : "",
					"text" : "The connection mode 'closest' tries to concatenate solutions the shares things in common (instruments, notes, dynamyc..)"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-30",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 11.0, 705.666687, 96.0, 23.0 ],
					"style" : "",
					"text" : "Brahms_4.wav"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-28",
					"linecount" : 4,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 401.000031, 673.166687, 158.0, 67.0 ],
					"style" : "",
					"text" : "set Fl Fl Ob Ob ClBb ClBb Bn Bn TpC TpC Hn Hn Tbn Tbn Vn Vn Vn Vn Va Va Vc Cb, bang"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-47",
					"maxclass" : "button",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 339.433319, 623.299988, 24.0, 24.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-45",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 696.999939, 695.166687, 126.0, 23.0 ],
					"style" : "",
					"text" : "orchidea.db.tinySOL"
				}

			}
, 			{
				"box" : 				{
					"channels" : 1,
					"id" : "obj-34",
					"maxclass" : "live.gain~",
					"numinlets" : 1,
					"numoutlets" : 4,
					"orientation" : 1,
					"outlettype" : [ "signal", "", "float", "list" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 179.5, 926.900146, 151.0, 31.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 294.5, 575.0, 210.0, 31.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "target",
							"parameter_shortname" : "target",
							"parameter_type" : 0,
							"parameter_mmin" : -70.0,
							"parameter_mmax" : 6.0,
							"parameter_initial" : [ 0.0 ],
							"parameter_unitstyle" : 4
						}

					}
,
					"shownumber" : 0,
					"varname" : "live.gain~[2]"
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"bubbleside" : 2,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-21",
					"linecount" : 3,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 128.666672, 691.833313, 185.0, 69.0 ],
					"style" : "",
					"text" : "The segmentation and connection modes can only  be typed in the object box"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-31",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "float", "bang" ],
					"patching_rect" : [ 259.5, 860.900085, 109.0, 23.0 ],
					"style" : "",
					"text" : "buffer~ targetdyn"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-26",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 259.5, 829.899963, 71.0, 23.0 ],
					"style" : "",
					"text" : "replace $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-6",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "signal", "bang" ],
					"patching_rect" : [ 179.5, 893.900146, 100.0, 23.0 ],
					"style" : "",
					"text" : "play~ targetdyn"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-51",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "", "bang", "int" ],
					"patching_rect" : [ 393.5, 860.900085, 40.0, 23.0 ],
					"style" : "",
					"text" : "text"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-43",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 49.800037, 860.900085, 35.0, 23.0 ],
					"style" : "",
					"text" : "stop"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-41",
					"local" : 1,
					"maxclass" : "ezdac~",
					"numinlets" : 2,
					"numoutlets" : 0,
					"patching_rect" : [ 11.0, 974.900208, 44.0, 44.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 565.0, 687.0, 36.0, 36.0 ],
					"prototypename" : "helpfile",
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"channels" : 1,
					"id" : "obj-42",
					"maxclass" : "live.gain~",
					"numinlets" : 1,
					"numoutlets" : 4,
					"orientation" : 1,
					"outlettype" : [ "signal", "", "float", "list" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 11.0, 926.900146, 151.0, 31.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 565.0, 615.0, 210.0, 31.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "solution",
							"parameter_shortname" : "solution",
							"parameter_type" : 0,
							"parameter_mmin" : -70.0,
							"parameter_mmax" : 6.0,
							"parameter_initial" : [ 0.0 ],
							"parameter_unitstyle" : 4
						}

					}
,
					"shownumber" : 0,
					"varname" : "live.gain~[1]"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-38",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 11.0, 860.900085, 36.0, 23.0 ],
					"style" : "",
					"text" : "start"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-36",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "signal", "bang" ],
					"patching_rect" : [ 11.0, 893.900146, 111.0, 23.0 ],
					"style" : "",
					"text" : "play~ solutiondyn"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-29",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 11.0, 829.899963, 226.0, 23.0 ],
					"style" : "",
					"text" : "orchidea.solution.tobuffer solutiondyn"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-23",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 393.5, 829.899963, 144.0, 23.0 ],
					"style" : "",
					"text" : "orchidea.solution.totext"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-24",
					"linecount" : 2,
					"maxclass" : "newobj",
					"numinlets" : 3,
					"numoutlets" : 2,
					"outlettype" : [ "", "" ],
					"patching_rect" : [ 11.0, 762.833313, 889.599976, 38.0 ],
					"style" : "",
					"text" : "orchidea.solve @parallel 0 @segmentation flux @connection closest @onsetthreshold 0.01 @onsettimegate 2000 @partialswindow 32768 @partialsfiltering 0 @maxepochs 100 @exportsolutions 0 @negativepenalization 10 @positivepenalization 0.5 @sparsity 0.01"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-5",
					"linecount" : 3,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 11.0, 546.181519, 542.0, 50.0 ],
					"style" : "",
					"text" : "Use threshold 0 to segment at any minimal spectral variation and increase it to reduce the sensitivity. If threshold is > 1 than there will be no onsets and target is considered static. The values for timegates depend on the specific problem."
				}

			}
, 			{
				"box" : 				{
					"bubble" : 1,
					"bubbleside" : 3,
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-7",
					"linecount" : 4,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 242.333405, 355.119598, 307.666656, 69.0 ],
					"style" : "",
					"text" : "The output of the segmentation stage, is a set of segments that are treated as independent orchestration targets; a connection model is applied after orchestration (see below)"
				}

			}
, 			{
				"box" : 				{
					"autofit" : 1,
					"data" : [ 21312, "png", "IBkSG0fBZn....PCIgDQRA..CfH..P.JHX.....RK.uq....DLmPIQEBHf.B7g.YHB..f.PRDEDU3wI6c2yibckt1X9dLDvqDN.GHxHofCXSPAanw.13HLLvBFfjSfzeAEY1LbXnOgJnICT3jJExlY7u.Ev6PxD4.JnwNYDLfnYSXaH8lvVd.LnbjbPseJpdqtXUU2UU6uttRJ1jM6dUes20ZcuedV+ge8W+0eM6BW9xyt8d2a1sW+56jes6L23Fyt8l2b1s6uemMT5Dt+O61o58+ypG+3Y2dqaM61m+7NanzIF62+O5nY2VG+eGc5ldiM88+y5wY10uN6O7GN4um81a696qqM0t+1l6+ytcpb+uu+4421Gu6r978gGN616e+Y29nGsIGUab+W00C.....5GLAQ....RhIHB...PCSPD...fjXBh....zvDDA...HIlfH....MLAQ....RhIHB...PCSPD...fjXBh....zvDDA...HIlfH....MLAQ....RhIHB...PCSPD...fjXBh....zvDDA...HIlfH....MLAQ....RhIHB...PCSPD...fjXBh....zvDDA...HIlfH....MLAQ....RhIHB...PCSPD...fjXBh....zvDDA...HIlfH....MLAQ....RhIHB...PCSPD...fjXBh....zvDDA...HIlfH....MLAQ....RhIHB...PCSPD...fjXBh....zvDDA...HIlfH....MLAQ....RhIHB...PCSPD...fjXBh....zvDDA...HIlfH....MLAQ....RhIHB...PCSPD...fjXBh....zvDDA...HIlfH....MLAQ....RhIHB...Pi2pqG.vXxQG+Ky9Cub1s6cw2tCGM...rdjfH....IQBhvF0ce3ySRx09e73jjr+Ee+tb3...vZQBh....jDSPD...fFlfH....IwDD2Zt6Ce975QC...XHvDDA...HI5hoab09f2g+e+iII4fO8xc4vA...XkIAQ....RhIHB...PCSPD...fjXBhacG8xeIG8xeoqGF....KkIHB...PRzES2ZpTCe7yNNII6ew2uKGN....KkDDA...HIlfH....MLAQ....RhIHB...PCSPD...fjXBh....zvDDA...HIlfH....MLAQ....RhIHB...PCSPD...fjj7Vc8....F7N5nY2t2dc4n.XWXce+9Kdw1ZjrUHAQ....RhIHB...PCSPD...fjnFDAfcj69vmmjjq8AuaRRt9UtPWNb..3THAQ....RhDDA5Qd7yNNIRVZrpd9sRPD.f9GIHB...PRjfHrUb+m9iIIY+q99c7HYX3nW9KII49O8mRhDDA.fthDDA...HIRPD1Jd7y94tdH...aE28qm0UpO35WuaGHrUHAQ....RhIHB...PCSPD...fjnFDA.lFN5ntdD..C.RPD...fjXBh....zvDDA...HIlfH.zQt0C99bqG78c8v..feCSPD...fjnKlBzCczK+kjjr2Ee6Ndjv1P876ie1wc7HA.f1jfH....IQBh.8HG8xWkjja7UeWRRd9m+wc4vA.f2f+v+weKII+5e8O2wiD1jjfH....IwDDA...ngIHB...PR1k0f3QGsy9U0op6mu0+0c5v...fMpoxmmehSBh....jDSPD...fFlfH....IwDDA...ngIHB...PRLAQ....ZXBh....jDSPD...fFlfH....IwDDgspCe5OlCe5O10CC...VIlfH....IwDDA...ngIHB...PRLAQ....ZXBh....jDSPD...fFlfH....IwDDA...ngIHB...PRLAQ....ZXBh....jDSPbq6IO6mySd1O20CC..Xq4vm9i4vm9ic8v.XCvDDA...HIIuUWO.FadbkV3+Mc63....XcIAQ....RhDD23dwKeUWOD..fcppeKre2NL.1.jfH....IwDDgsJcwV..fgDSPD...fjnFDgspiTSp...CHRPD...fjXBh....zvDDA...HIpAwcta8fuOIIW6JuaRR1+pueWNb....lSBh....jDIHt083mc7o92e2u94IY7kf3QG+KIIYutcXvHU89o8tv6L61K91c4vA..FcjfH....IQBhrgc2GNKYzCtYSRhR3gMn4u95SubR75K..XSSBh....jDSPD...fFlfH....IwDDA...ngIHB...PRzES2YN5k+RWOD.fwfW7htdD..iXRPD...fjHAwstJ4viN9Uc7HY65w+vwy9C+21siC...3rSBh....jDIHx4jZqjMoiN1qm..56d7O7yy9C+aWpaGHrUHAQ....RhIHB...PCSPD...fjnFDAFflW6qWoaGG.vL68O+otdH.rgHAQ....RhIHB...PCSPD...fjXBh....zvDDA...HI5horkb2u94II4de1G1wiD...XUIAQ....RhDDYK4nW9ptdH....qIIHB...PRLAQ....ZXBh....jD0fHrUczw+RWODX.4Fe42kjjC9zKmjjqekKzkCG.fgoiNpqGACZRPD...fjHAwclidojj.foiG+reNIIWeutcb.r8UeN28t3a2wiD1DjfH....IQBh..rEX+vEfgIIHB...PRLAQ...3b39O8Gy8e5O10CC1PLAQ....RRGTCh28qedRRt1+1+8Iw97E...CY12mGWjfH....IoCRPr1mTtTsu.dkc8H....fSiDDA...HI1GDAfcjG+reNII27pueGOR1Mt0C99jjbuNdb..rNjfH....IwDDA...ngIHB...PRTChctG+riSx3Y+fbu+4Okjji51gA...bFHAQ....RhDD2YdQsuO1n1OHOx9AI.LB8jltV6Kd3ySRxAe5k6xgC.rhjfH....IQBh..rEL+Jj43e4M+MB.8JRPD...fjHAQ..f0zM9xuKIIOpiGG.adRPD...fjHAQfdrK+EeSRRd9m+wc7HAXcczwuJII60sCC.XMIAQ....RhDDA5wN5k59gvP2Qu7Uc8P..VCRPD...fjzgIHd+m9iIIY+q99c0P.1Yt0C99jjbvmb4jjr2Ee6tb3.vNyQ1GDAXPQBh....jjNLAQqn3zvie1wII4I+vOmjjC9zK2kCmNS83vAYZd+G..XXPBh....jDcwT1RpDhqjCkXLvTyd+yepqGB..qMIHB...PRjfHaI09WWU6c6cw2oKGN...vJPBh....jDSPD...fFlfH....IQMHB.vFPU6460sCC.3bRBh....jDIHB.vFvQG+pjHAQXJ5nW9ptdHvFjDDA...HIRPD..XC4Fe42kjj68Y+wjjr2Ee6tb3vNxie1OmjeSsH648AMIHB...PR5fDDqUVH+a65eyvtmUR6M6ni+ktdH..aPNtNL7IAQ....RhZPbm6wO63tdHPGXdx4..i.sSJ7w+PSMn8u47cvPmDDA...HIRPbmSRRvqMuFM61gA.rhpqDJedFX7RBh....jDIHtynqdA+dG8xWkDIHB..8ERPD...fjHAwclCe5O10CAn2y9FI.8ap8vE3nilc6d60kiBXiPBh....jDIHxNR00ypau9UtPWNb...fSgDDA...HIRPjcD0r.P4ENd..PukDDA...HIRPDX.npcUFG77I.P+kDDA...HIRPjyoiN9Uc8PfIf6+zepqGB.rRp883Z+bUW6FXnQBh....jDIHx4zS9geNIIWqiGG.CGGc7rtXZ0cis+nxXxSd1O27md2Y2bkNan.vYhDDA...HIRPryY+.CXpw9hJ.iSUuonpA25JD4tO74II4Q29i5lAFqEIHB...PRjfXm6vucV2N6fO8xc7HAftUsByW6ClU6VpIQFRdbSsGdz+e+qII4ZW4c6xgCzIleEhn1aGzjfH....IQBhzSc4u3aRRxi9KytV0qqkcfwqpVUpDDggjid4rZu5w+zrjDu4Ue+tb3.vYlDDA...HIRPD1HpUNdu+kepiGI.8cURoUs5rujl.fdDIHB...PRjfHPOj8IOFypWe+jltdoDDAf9DIHB...PR5AIH1No.cqR...ftgDDA...HI8fDDuwW8cII4de1GlDIHB...zUjfH....IoCSPTWJD...neQBh....jjdPMHB.vvmqLH.FGjfH....IQBh.v1xQGsZeaMIO83m8yII4fs03gspWHAQ.FEjfH....IQBh.8.68O+otdHzojfFSA25AeeRd89dL.zOIAQ....RhDDA.XKpRH+nK7pNdj.rsoVjGGjfH....IQBh...aX2+o+XRRt1G7tII45W4Bc4vgcj670OOIIG7oWtiGIbdHAQ....RROLAwCaVwoZkl16hucWNb3bp5Ji..Lc73mcbRRtT843tRGNX.VKRPD...fjzCSPrtl0qjCkfHvTU08GcbP.XHoRPlgIIHB...PR5gIHBv55vVW4Aiktk2M9puKIIO5u7QIY7ljn8MK.FWdxOLqGTTcwVFVjfH....IwDDAFAt+S+w40uL..vYmIHB...PRTCh.C.G8xWkjWuuZdyq99c4vAXEr2+O+WRRxQ+quWGOR.f0gDDA...HIRPDNWp8ot517uzgClQriNVWtbLy9kE.SC1eeGFjfH....IQBh.PGqpsT.XbpNN+QGOqmBHAw9MIHB...PRLAQ....ZXBh....jD0fHrSUcqw8un8wOfokwdsl9Bca4Sv9VKLbIAQ....RhDDgcp690OOII6aEUgE5VO36SRxAexkSh2uvvvi+glDR+2tT2NP5YdwKkrJLzHAQ....RhDDA5POooFU1uaGF8N2+o+TWOD.Xinp89Cxk63QB6RG9s+XWOD3bPBh....jDIHROyce3rZz6H0r.SXG9zYq75dW7s63QB.v5q9bbGsft6akrb45W4Ba8wDqNIHB...PRjfH...rC8je3j6KpRPreQBh....jjdbBh09f0y+7OtiGIrMUWi52+o51U...z0jfH....IoGmfHiSy6NoWo4qO9UI40cyJWC5bZF6c0189m12CmRt+7tT66zwiD.1tZ2sRYXPBh....jDIHB.vNzk+huIIIO5u7QIw98I.8MRPD...fjHAwdm69vmmjjq8AuaRTSd..L9T0VtDjg9GIHB...PRjfXuS0smpDDmZN53gU2pr5Bq..rb0myothodzs+ntb3.bJjfH....IQBhri858+qSVyAO9Y+7r+9AVBh0JfdPGONFZpZOYru+FxYiWW..zcjfH....IoGkfnULdZnRJbcSb6Fe42kD0p..LrcqG78II4de1G1wiD.NcRPD...fjziRP7te8rZ4ZuKLs1ObpjSqt50YMgswt5wE.fgrCapEeIHBzWIAQ....RROJAwoN0f4oy9LH.CCCs8wV.3zIAQ....RhDDgNQkXb68CRVOUs7.z8pZoGVGW9K9ljj7n+xrtTtyK1OM+ysbF++wvhDDA...HIRPD1opURqpsRqT54Ssehc8q7tc7HA..FGjfH....IQBhzQl50f2ce3r88yit5rGG1+pueWNbFbtuZObRpp4zWzb7iC9zK2kCGfUP0caqy6coI548ggDIHB...PRjfXuwKzkmfUl8asog690yRb35W4BIwwIggn5JF5vuc1U.vAehj+g9NIHB...PRjfH.zSY+yB.X2SBh....jDIHBL.IYI..X6PBh....jDIHB.CLO9YGmjjidvrjju2m8gc4vA.XTQBh....jjAPBhUsFs2Ee6NdjPW3tO74c8PfsfJAH3rn1GL26huSGOR..FejfH....IoGkfX6tRX80URCWOWX1e+wuZ1WekKrCGczUd7y94tdH.zSTIGB.zkpOe5d+2MNuRGkfH....IoGkf3xb+m9im3qkfH...CW0UJ3A4xc7HY8T8HiCt9rqrQIHB...vnTuKAw10h3x99t6WOaF71Gr..XnXp1k1ehdK.+F50D8SRPD...fjzCSPbUUcyzid4q53QB..bRURY6e02uiGI8CyuBwtR2NN.VNIHB...PRFvIHN1b32dxtz5S9gl8WkK7NytchTiBqZMnB76MeeiUWdF5bG1z80W2djP893h2OC8W0mWer89TIHB...PRFQIHVq31XIwsJQwK0b+X+KpFFfol0MQ8a7k+8jj77O+iSxv+3fPe178AsM7O2JQhxXKYBXLo975G7oCq8wwkQBh....jjQTBh2+o+TRRt1Ud2jHws9t62TaF2T2cCXhppQs4m2xwCmTt0C9GII4Q29i53Qxt0quhubEN.8URPD...fjL.RPr1GgpUbZ++jUXcL3nim1cqzG275ZInNsUuOXutcX.Pmq9bdO4qmc9w0s6uBr4HAQ....Rx.HAwZEkpt4W6t6I.S8Dooex955oyiKbZdgWWvHPc7sgdWDWBh....jjAPBhsYkGm1FKqLCrNpt96XaeVZrpNNkyWAvIM1Ot3M9puKIIO5uLq6DOT+7pRPD...fjL.SPj9gtZEfpZR8te0ySxq6xYW+JWnSFOaa09jl8Gsyl50oC88ar508GjYIHd2GN60+RTD.FRt6WO67W1UB52jfH....IQBhbFUIZbmlUB5Q63e+i8qg8xsdv2mDIHdVczwupqGBaE066jfH..aZRPD...fjHAwdqoRBY..Lb7jm8yc8P.XKSBh....jjIXBhaq8QuidYSsN8urQ+wBrFpt640u83rq1V096T27qvhqzsiC.Xy5O7e72RRxu9W+yc7HYZSBh....jjITBh0JNeiu56RRxy+7OtKGN+Np4vymK+EeSR5eOuBaBOtolet9OrZ09SsOSU6SnvPP00l85V.5VRPD...fjLgRPjwMIvBiW09Y4XoFLO5XGu5zb3S+wjHAQfgiw5m+TBh....jDIHB.8bUsoMVVo1wx8CVMUx2W+JiytqLv3iDDA...HISfDDqUd9lW8853QBmlWXkzAlHFK0P4lR83w9W7863QBPWyUVQ+hDDA...HISfDDqUnTBh8K0JEc329imqeN2+o+zlX3.CR06i16hucGORXUXExOo5J7o12NAnuZ94a61gwNiDDA...HISfDDYbaQ0zyM9xuKIIO51eztb3r1pUNu5tcRBh0gZ3ZXoRLioo0MA4582GjKuMFNcl4IwbgSd9t5JJR2dcbqd9ensevN+7sc6vXmQBh....jjITBhp8iwg6+z2bMKNzVYpZ7JInymEshzSERlB5+V2Zs7wO6mSx3sViq6ekw18ONeZ+4185icKIHB...PRlPIHNTYeB7jFJICttdRyJot+UkfHquid4qdi+6CkZxcpp8UFgiCvTz7DitR2NNnaz93fUh6W6JuaR59qvpo1mGWBh....jDIH16MVSL6rZY0R5QG+lSRYrv0l+a1TolieRqZ3YQZWqOzuTO+Tcuw69vYqb9Ae53p6UBvhbd2WrYyRBh....jjIbBhs2+75q66N03brlXzTIomkYQ6mis+2qWmVeckfz89rObKN5Fdt7W7MII4Q29euiGIaWKq1CYXothQlu+2IAwIIW4PyTIoeylZxsu74dNroV4pZja85MsrHK5yCVONq1r2sjfH....IYDmf3hRdq7je3j0jSeMAwxsdv+HIudbZkkmVpUR852te+5ztlUdel53e0qaF5Vzwwaeb99RBCaaySNdhc+dnxUJyYSUSZ2rmjbz7iqtl6mkvPjDDA...HICfDDOqq71XYE6p6G0s88jN4rod98VO36Sxhqovp151+O0OVQ09t5wy8tvzJgkwxw+Vlox8y1p8KrK0jnQWu+fsoM1RDtd9ZuK9NazetUsvU6Oatxh1slZG+oRPc+M7OO5mjfH....IY.jf311lplkluRR+KajebrhFaqfmtRIL7MU1OV2Vd7HMYzyqCmmD4rjUewH67eKR85gW7TIkNlrpe9s566Fe42kjjGc6OZqMldStSSsmdvZ9+qF+2+g+eL6+++oM4nZ6QBh....jDIHNeE4rOxALz73m8yK+ahAu57T62sCidqp1re9m+w6zeuy2uJ2Q+9pZYbpkfVkTptT8zV87+x5UCckw1UzlDDA...HIRPDfQKcItgs54u6KAw2ntZk62VI3qVzgeu4uO+Jc63XQFa0dtDDA...HIRPDFjTKFrJTihci6+zepqGBLfspuusRX19iLvllDDA...HIi3DDehUNmQr4c0vqZeBCfjWWiR09D3XUc+rRZTBh.aZRPD...fjLBRPrVAs8ZpIqqck2MIuNgkU0ptxiGMe+3YV2JxJ20u7jePxw7Zyee8EF2IJ...aJRPD...fjLBRPrsWrk2OjptF1Sbs+2KYeeiwLcu1ws5JeYrWCcKyc+5mmjWe90w9iGSkZmbUYefjgntZ+XcaQBh....jjQXBhG9sqWsG11ce3rUt7ZevrZYTBg.aKySNXk+9sx5uI0UPP83pt76vzXak3WjpGJTutc+K50qIu9JkXp75.Nciky2c+0rmnzWHAQ....Rx.NAws0LxqUxqRPbnpteHATn+ZcWgT0f3oq5pz23K+6I400x0ToF1fwjEkbX84Zt0C99jjbuO6C2YioUw78kxq2siC5FsmWR8004s2aWOfNmjfH....IY.mfXsRMEcArSpVI8e8u9m2J+7GpWS08csecMaV23K+tjj7na+Qc7H4rQM4LsL0e9tNOykZNud0kxGZ8Hf5356ew2oiGICaye+vU5IiC5T888k76zzMlGp0BuDDA...HIC3DDoaoVnXHo8qW+C+G+sjr8RXmcq6+zepqGBaT0JiW0Z00uxvtl3WlEkHS0UxamLvk5IIIstFKckQnOv9R91kDDA...HIRPDFDruPsazW6NdaZis860CUSzcp16+jb5bk2LMc4u3aRRxy+7OtiGIzmTm2pu1sskfH....IQBhKTsB6W+1C6UVmsqs0JBWqH+7eOVY9Mhk83Xshdi8DDGK62qzOzUGep8wI66V1iS0m6fSppE09t4c28qexD0c96okk87cUKxOoUWqe+K1u51oRPD...fjLgSPbnsxirZp8ap5Z4tVQ1C9zKmjWuxN23qlse3cVqIfs8JCV6ikqK6GnvzwcG36yVKyx126Vzweqyuu2ElsuC12Od3KluetIoogr1udrpoc1tp2uW2d8NZbL1d+qDDA...HISvDDW2DejHyvzT6Z9eSkLJLEztqaNTSfapcbtUU6qbDm+FFdV0D45K05YW+6eSSBh....jjITBhs6VPKal9UsrUqzbeq6BUi+a8f+QRRdzs+ntb3PGYd2n7Y5Fkvp5I+vOu7uI5spZ16RRFjAnox9sKCaRPD...fjLgRPbr00RO53W00CA5ApjjewH6Ze+rZrUC..+d09h2AexkOwe+t57h8siyL15dhicSk8aWF1jfH....IYBkf3Y0PIYlZEoFpciuckZeCC30pqvhp17pt+HCCi8ZZ5nWNKYv8t367F+9p8OVcszSpcWcEfkQBh....jjcPBhyS1Za+KZINq0Lv7ZcnmtxaUsGTIiIAw2rZkne8WexG+Fqq.Ojjb4u3aRRxdW3jIrLeejRsLMHM1pw9ol46KmK38e0+d0c0u4Jdd958024qkf3tTeqFUgyBIHB...PRTChystc+r1IQwvT87tmOmlpZ2Zp77esx1sSPbpPRazG83m8l2WNa2KDteyUl0TwPKQto1yOaKCsm2GajfH....IQBhyUcuuUUshe65U3XdMJrliWfeOIJMtUO+t+EmUyVUWt7NehZwZHoNumZjcFON.SOUOco5RyW+JWXq96SBh....jDIHN3HwCXyYdM40Q6aZuniRBntBHN3282O63Kik8Msmzb+rc2ctRfYpVKlCMsuRcrOGtaTc83G8W9nj3w8U0xpozxM9xuKIIO51ez1b3vHQUaq6pyKKAQ....RhDDWY5lRCa0JgxzTe88u8swU68MsZ+VapjbfjpFG5auuBR98utTsjRelDDA...HIRPbopU7Qs+AL0b2ljDu2m8gc7H4ro1eKW0qff5960tx6ljW28S6Zy6hm0904+RGNXXmSRSiCKa+Qr5RksqYZNc09XbeW875cNi++qdBvh5c.aKRPD...fjLBSPbpT6AqZ2Wrq6RicsoRxuG9su4Ulru4ESj2mNzUq74PMAwwhox40VWKKAgZ+M99O8mRxv80wySNlAsp1taqd+ccELrq1m6Fp79gcCIHB...PRFgIHB+Vs2OhpUla9J18vm256eVhiCsUbdnkTrZpgso58CRdaZq8UVgZ75zM3N+wHMAoe2wstRGNXl.pq.ggxmyqTWYD0saq8EQIHB...PRjf3fiUDe6Zr73akL51ZkklJpWObiu56RRxy+7OtKGNab0Jndvm7lecRkrd83gDXnKstGmt99Gp09b6qDlMs4091ElkfXe+7Fa6GOXZnuTi80wkV0qvgEcEXsouBIjfH....IQBhycVqIpZk02aCNVX2oVIxp1Kdx.ekImWCCpwO1fpZcfUy157BySNy9f3JYrbEgz1htesrZIrRXnNO2Mu56cx+8lZ1rumfHLlTeds57FUBf0WurtTe6tf6plfXc7fpa4193FRPD...fjrCRPbndM+upteyLvOniGGKxQGOqaeMT5NYck4Iucg5wq2oKGN.blciubVMy9na+Qc7HgcopVoeze4M+79qqo3ww46FZcg01t0C9Gc8PXTqd8deaekbQu+qd8b0i.V7ULvr++0myecMu1i+r2tYbHAQ....NEpAwAt1qbVsRIkp1gpUNoVQhqck2MI5Fg.bd02RvPWdbZqRFXYcm3EopMogh5y87jud1q665tR4408sec9FsriuU+6Weg+6Guf+kci57E03b+lDDqu99q36+pu+a1Jgw58u0Uv4YslhkfH....IQBhiN51fv42Xs6GxlUsRz09NpZ9qeS2cd0TWoQ8kDwmZ75zymp17J0qmqZys95U+m2v54iMUueQBh....jDIHBvRWg.FDOvX...H.jDQAQ01cUrgdMtv3zPakt20pZyYr+92ya2Mbnvq242pRN6Rs96OuuNou89n1IjtsHAQ....RhDDg2nW2solUqQ5pXSCm2t.HzEpW2xz1h5tgiMU2d7vuc1s8s84tMk9VWRdrppk7yZW+7rZc6ppqaWp9rd+RBh....jDIHtxpqs4ZkpJ0L4OXmOhVM5FVmO00ddsRk0JT106iNrcU0pzMu560wiD1lpiOtopko50MyWw+MxOUfora8f+QRdcBPi0jR6JG05y2uqSPr84e1Tet85mS84UkfH....mIRPrQMC68tvoeMdW+6Cstl0ToqssqTuNnRTDlBtSSsscm0rlLqqvhquoGPaHG158wU2g6ZW4cOS+71T6+TrcU0jyMapo7oVscMOg6E74cXX3Fe42kDIKN1z97RcEIHB...PRjf3bCsjA4rwyyrMTqj689r+XRldIRrH6p8qoyq1WgH27L1shuitH5fPUqQm0mm6aluuG57aSR2+o+TRjf3T0SVPWMsRh7r94QjfH....IQBhqrgR2.cUGmun096mUd5jFJIeP23VO36Sxq2mDGJGe..Na1VIztt6qc+9++5p5mGC88O1s0y+RPD...fjHAwQiZksdbVsURn894nDDOoZE8toZ5XRqpsi1luuBkc69kz1htuI76WI9g94E2Vca69xUXyPO4L0L5l0788ulyau+J9+67Vqdcs4ck3kL9quuZe0bYjfH....II4spUf4I+vrDSp8SkEQMqMLUcYw8t36zwij9s10R1XKYEu+c8zW1Oh1VpUTbc69lq5JVNz097iW6Cls+HNVe+Ss+.trOGvXUcECT6OfC8mmaWaaC8Zsps592X+3PsMuqKuiq88paYt+N825paYIaezw8iju6Jq66+kfH....II4spUBdQqDQ8uWy7rV4hm+4e7NX30eLzuVwmesYOQWwsU0P+441ZeMmWO++q+0+bmMlX3pNNxM9pYWQBi0yC7hVm2qdezi9f+8S86uu1EammH3+oS+eu8UTPkj7XOAww1w4WUap6280WuOUTuudWekbzWp8zEo97MW+L9++0edoYco768Ye3FXT08p6WG9xSVqkK53A0qujfH....I42zESWT2fptlcG5cKpohy6JD1NwoGc6O5bOln6rs5hcPxu+3E26y9iIY3cEJrniaNTRZZ9UBzEVsU3u8Jku+e582NCrAt5y8T0l3XIQgRkD3xtBxZ+0Ck2WL0U0P+9Wcy79aIGONrpu+UBh....jjeSBhVQnYlJONrvULeh2kmZanuhYqa2oj2r4cOtIxwIVjWW65up41o8iGCcd96zM1eed66eCsj+4jZe9o6uoSPbj79gwx8isk57ARPD...fj7aRPD32qtF9u9Ud2NdjrdTyvaG+tZxQh6SRVA5wg58us6R6CsZxr89c3lV83TUKlCEU2XrLz5Nu09W87tO+Rd7u88WNa56cq0EYd2J8aOe8dh5y8JAQ....RRxa8hUbkP2062JraUq7zk776oZauBsaZR3X2n89QEyzt6OteGNVNKV1JvV2+tqZ7cPa96eOV247ModbouekorsGeOYG84.VT2hcQIasnu+g1U9DaFq6wwdxOb5utVBh....jjj2Za2kCqUz4fs5uENupUL+fOYXcM5CcokkrbkPQ6ZeouuR7KR6w8hpIogdRLC8w+xro2eT2UIqroMu1tbkyLJL1ee65pd8cUKi09Zccb7qekKzMCrAlEkv1XQ85g1W4LRPD...fjnKlBvVScEZbsOXVsfTqXashjCsU7t83cntuPdVSvsRLsul.7pVqzm2tb2Xyhdc8Mu3627u+pS78o1SoKbdqU140NcyU1x0usDDYw6CtRPD...fj7FRPrVgha8fu+T+2cMLOrLzVgeXH6vV03Uk7jiWNrMz1erluxvu258+ape98JI11I1LuVc1v0vImOs+7M1O.47nde+T+0QRPD...fj7lRP73SdM221M9x+dRR90+5edKLrnuZnVyQvtPcbyMcWhbn3Fe0rtk29+o2uiGI6V80iGNOoq+e+eOII2q4ueY6qwUMxNUSPrzWedcWqtRxFJc60pFaqW+t2E1Li6g1UP.mzp99446qjMIItod8Se0hNefDDA...HIavtXZsRkyWwlAxJMw5oRNdpppMkqek2siGIzGUIurpcSxwloRhKKKAtgtJAl1ce2otg5983pZr892JwuMVBhKnaONTz942WmT1ISFcr998y5U1yTsqOKAQ....RxFLAwZl40JpNVWYU.VW0JYO15JZC0DGNqi6gZBBq6824IKT++txldDML0W2+K4z85q3mKz5ue1yi6cg2Y1sMed0w5UFP83P6qrka8f+QRRt4UmUy3OYAOdMUM0d+d6ySHAQ....RxojfXMCxpVZVla7ky5ZcC0UVkSp5VYpwt2roZMlwa1hNNX82O02e4fgrgZh4bR0my4de1GljWWCd0U3wit8G0MCL5Ul5ueWBh....jjSIAwZerZk2uPVRxgRVrey9Z3zTk7uUJcyZpUyBSMNN4LsqgKlFF5u9+2UasLoX9HqGIHB...PRNCcwzyZ2Pi9IqnBmEi0t8FvxU0p0Ae5k63QBrbUh2WZMOe0TolwG66umEyGY8HAQ....RxanKldV0t6PQ+lUTgyhZeOsHIgY1T0tMLjT6ymPeP6iCWcc78t3IqY16+zeJII27pu2o9yo97rO5uLtqU+CaNe99M6Gh0ie044q8IQlVjfH....I4LTChKiDoFWpZM4Zef8EwwjJAKI9uaMekrad7euNbrv4my2Mi8EVFhpjy16Bpk9eqp1KuyWO6y+4JdYZRBh....jjMXBhVI0woZkitjmeGUluePcA0NTWXdWfsaGFaMVw4ggU83.y+9N1wK.XJPBh....jjsPMHx3P6Zk5ZWQMHNl0tVSWz99T6ZS3NehtWJ+dUs8b8tcXv4zKZRN7tOa162UqVP2wUpG6RRPD...fjrESPzJc.8eURwUMiU2tnDD895yFOtQe1h5Bo0ULP6+88t3rjDqtfLLDbV2uNu7W7Ma3QR+ftOLuIRPD...fjrARPzJiCCeyee7U1t+dpDITiZvvmy+yPxxRJG30jfH....IYKVChOw01LL3T0nw78ouK9l6Zg0JudzCl88euO6CWxOeIN..8GsSVz4o.IHB...PisVBhUMFw3vKrhZSBUWL8Fe02kjjm+4e7J88WptZ3xRRDn+aQ0rkDVXLa9UFyD8045NwjHAQ....Zr0RPjwk670OuqGBL.TW4.RPD.X3XQ6Sjm08ORF1jfH....IQBhrDS0qAeNoJYv0s6De2GNK44pVEu1Ud2M6.C.fysEuOQZWIXJRBh....jDIHB7Fbiu76NwWeVWIwJAxp6vA.zGoqsCRPD...fFRPDXt10bZ80WeCU6fpoU.nO6vu093MHAQ....RhDDA..HItRWfDIHB...PCIHBrT09X3hzt6lV6+g5Zo..vvhDDA...HIRPDXEnlL..foAIHB...PRjfHvVPUyhsqMQ..f9MIHB...PRjfHvVvQu7Uc8P...3LPBh....jDSPD...fFlfH....IQMHBbNrn8GwpKlB..LrHAQ....RhDDA1BVTxh...8aRPD...fjXBh....zvDDA...HIlfH....MLAQ....RhIHB...PCSPD...fjXBh....zvDDA...HIlfH....MLAQ....RhIHB...PCSPD...fjXBh....zvDDA...HIlfH....MLAQ....RhIHB...PCSPD...fjXBh....zvDDA...HIlfH....MLAQ....RhIHB...PCSPD...fjXBh....zvDDA...HIlfH....MLAQ....RhIHB...PCSPD...fjXBh....zvDDA...HIlfH....MLAQ....RRxacm+Wt+N8W3M+GOLIIW++q+W2o+d2116e9eY1e3+y+2RRxcxt8w0tl6+S66+mUWpdbqwt93Qcsw98+w98ukYSe++rdblt54gw546Wjo1821b+eZc+uud+cWc7t089+0ZNtccb7994CkfH....II4Obm+G9e5W2E+hN5e88RRxd+yeZW7qamare+aYb+eZe++7Zp+32X+9+X+92xrot+ed+4rqddXp878T69aat+Ost+OTt+tsFmCkiCedIAQ....RRxeH+O+edmjfH....8aRPD...fjXBh....zvDDA...HIlfH....MLAQ....RhIHB...PCSPD...fjXBh....zvDDA...HIlfH....MLAQ....RhIHB...PCSPD...fjXBh....zvDDA...HIlfH....MLAQ....RhIHB...PCSPD...fjXBh....zvDDA...HIlfH....MLAQ....RhIHB...PCSPD...fjXBh....zvDDA...HIlfH....MLAQ....RhIHB...PCSPD...fjXBh....zvDDA...HIlfH....MLAQ....RhIHBrEb8q7t45W4c65gA..vZxDDA...HIlfHvVjjDA.fgESPD...fjj7Vc8..X7XuK91m3qu4Ue+Sb6c+5mO666By99d7y94c3nC..XYjfH....IQBh.a.sSNrs8aRPrt8tObVRhRPD..5WjfH....IwDDA...ngIHB...PRTCh.uA0dX3QG+Kyt8k+xI92e9m+wII4Fe02saGX...aERPD...fjHAQfyfJYwRsuFVIMB..LLIAQ....RhDDANGp8+vGc6O5D+825AeeWLb...NmjfH....IQBh.uA26y9iIQWJEfot5JFoc2rdrqteWlZ2+YZRBh....jj0HAwo5JGASYsW4zU9+2ENa++..5St9UtPRRN5kup4VeNXF+jfH....IYCVChRXDlNZ20Ra6fO8x6nQBPWy4+AXbQBh....jjMPBhKqFkrxhv3w0ux610CAfdlplicd9wspV7N7k+XGOR.11jfH....IYERPbYIDdvmbxZM5VO36OeiHfdqad02uqGB.PGXr0cpaeEtsey42tVyUJyX6yyttWQe0iGG9TIFOEIAQ....RxFnFD2uUhBisUbAFypZJ7wO6mWou+y59hHP+mdF.uIW6CZpA8utaGGaJpoxSWcbfad02KIRPbpRBh....jjM39fXaRZXbx0jNvhHApoAOOOMUItMVrnZprd88ToqcemldIxc95m2wiD5SjfH....IYMRPrV4nitvq1ZCF5+pt6kDDGG16huyraOdVR.KJQfwV2qC1DjjFL9L+y6d0Yuu9IqXM5Oz75ZMb1UFlDD42RBh....jj0HAwJAgJAow5Jp.768na+Qc8P.nmX++jDGX3ppsvk0UVqdtPc67tzuO+KS.RPD...fj7FRPTWH8zolSXL5Q+kYID93mcbRrelBrXWxmOfQfpVCW0Ou6PoV7W282X3zHAQ....RxaJAwlUJ4niOYRYsulra6de1Gljj6NRqMg4OtLvSPTRnSSKZkEqWOr+EaUqE.SVNOwzT6D0F5O+OVSTy9R81U85liVRWdenXce8hDDA...HIIuUMC446GZMIjcvmd4jjb2GtdIAVyPcrlf3XWsxg00luUlB.X5X99.3KeUysC6jSFqt4Ueujr7OmV84xqdL.ql4uOnIAwCe4z5yCKAQ....RRxaUyPtRLrsatfZMjwo162kEq7D.SKG7Iy9bAKpljudqyS.CQ0qyWTu0Xn6ZyqASeNtwjsUs0VWIgRPD...fj7F5hoE6GhSSUxxEq7D..CUK5yy12SNbU69j2oIIzZeJs8tPvYkdSwzR87rDDA...HIqPBhmU00zstYZ+zxpsj16KdddbXqd9bd2JdCsxh7lsn8QN6eUvvyXY+ArRZ5NsNu9XulRqjQZ2iE56p8W71muXuK7Nm3qqdIR85x6lYO+V2u26yl852a7k+823umo1m2arseutv865ldLxy+7ONIIW9K9l23OGIHB...PR1hIHVqP98aVwiwxLyGKZuRn0WeuO6O1ECG1wpURhcK0zc+11pqvMTTIHb+m9Sc7HoeZ++zrOWyPceQqN9S0c5amfXo1e8V28A69l5ygV6miSUySH63S+wg40XXlkzXk73X2P47wc0UtfDDA...HIawDDYXoRTZQqnR6tZJCKRFfcg53Hi8qXjgxJOusL1u+2tV7pDCqtCYc6XuFhqZVOCzD0auuN+jA58icsoxUXz7yW0y6IC0m+dasaBTe9vpmjTesDDA...HIRPjUTshB1ODgkarmvxhLzSb37Zr0M7ZqRVqVQ6wZsJUuNdpT6ZK53UKp6YNTTI8V0hXeOAwUs6VusN+R8y8Q29iRxz4y6Uc0y+v+weqiGImtplf21Oez90URPD...fjHAQXsL06xgb9TqT4h1+QYXaY6urPeTkH7TIwzypKMxtxPptx6TUkT5Ty7tVaqZs9Q+kS93gDDA...HIRP7barWyIb5tSSRAKZejpuqVw3Z+vpse8u9m2kCGFoFJGe70qnZSRJMc0tZbOTters75tf7IqMpZE3q8KuwxUVQkDbsuwMz69yUssMUporsk5wwg9UHPc7rC9zK2wijtwpVCmW5hCitb54U83gZPD...fS0acsO3cW92EKzTYe+hYZuh4CUWZAqXDbZVTBZUxR2sUR5sSj6vW1u6BhKae+ZQ0V3P49240T63DsWQ8m7C+7I95g146W080tJQI66wiaq69b3jYeQr06uGJc+1sEIHB...PRRdKqTDLdrp6iRvlv7ye7Iyt4ECrjUVU08yp1iO7aO46upjToasnD9lmH3ENYME096a+ETS1sqUqwZhwq5mGbnlj5Xwt9yseyQRRZK6JgnuueHtqIAQ....RhtXJ7FMz12CmJ0JvP2Mu56kjgaRusWI1J4kJQg1IrMVTII0992PO49oRMFt2EemS70KplZYbXp755UUk730u8pk.47jJuxraF7IHdgoQWIcUUICunDokfH....IYGjf37UrafuxCCcpYfyFu9kMgp10J0J1MTee49+oYq7nUnebXdxBM2NT12+1TWgGse+4PwP83G6Ji0drQkzc68oUllNqGGbQ0bcQBh....jD0f3nQ6UP520c1ZVw+6zreks2ElkLVsRT2efV6LPeVsB1s6BhvXxkFXIXT0dSc6xVIcXWPODfeqGc6+8jr3jvqqvspmF73u7uuQ+8KAQ....RxtnFDshH6DUBgO9YGmjEWSB0JRLeeg5XO+.mWKb+Wajb7u5JM3Fa3UnjwgttFnpD.qy+sn2OdslZ0YplX3X43QiUUh1UWRdUqszZ+6aU+64Mar0MiOqGuSBh....jD0f3jw09fYqb5XsqdsqMzp4FXUzd+7qqSFhMipKcV0f9XQUCNGzb+6ZOa144dQSxKsu+57erIzW1ejWzwmcb6ymg5UXP85xGc6OJII+g+i+VRN6W4.RPD...fjHAwUVshL26y9iII4xew2zkCmEp891WMtsxoaV0JLcqG78c7H4zY+wZ2ZnVaOq5qSptdb88OTSPep99hk870ACz8AvR8759W7jq7ec+9tirjSYbq97ZG9RcW99fpKgdXOqa+W0T8h7q+0+bRRt6COaG+SBh....jDIHtFqf9aehuelVFZcCrZ71WS5droRt+niGmISMTOtW6Zprsg58qyqE00OKsST7nieUR5eWIJKK49594TOAwJI0C9fgcRwqpqufjUpDW56uuendEovtU6iiuoIAQ....RhDDOyp8Ik62ytljYyZnrhiqJqL4lQ85gJokmzpa1UIsTcOX5FUsibzKmk.V6Ddq2Obvm1773Ozsckvck50sO9qN8Udt8w65K0xd6w0MGncavcs1O+UWwTq540FJc0wZbVueeQ+68E8ktgJ8K07K55i2JAQ....RhDDmuBxqaWsqVIp51pVuF6cGupaFNTsnZNcQ+8c8J3roUIkvpYcWg2gVspdVMTRTu8wq1+OM630KZ+.rd+QUyV229AYuT87XW87xP+0C03+Q+kOZk99qDM56pq3mEkfXeyMmWCYRPjsmy5UZgDDA...HIRPbgZmnz78WPfQmyZsfTGm3IOaiOj5kl2MmGnWIAyqIzu978youVKuS084wcs5JKYn+38PMIz1i610T4it8pkLZeUcELz2pYRFlNquOWBh....jDIHtPudkxmca0M75qpUbZrtOrstzcv3rXYqzV6+8JIgwVsptn8Wog9JyyvV08Ukrxzzit8+dRRt0C99S8eendkMzV6dbAmjOe2tgDDA...HI6fDDuz.8ZbuVo7ZkpFKqLEqlZEp5qrBZiCUxiG9R6mp8I8sZyZUq0sJgsEkvxT0To6B2Vcdhg9U3P85+5ygUce0a7UeWRdcWVsu891Mse8u9m65gPuv7dBhO+yVkDDA...HIS3ZPb9JR0ZkHZuBTCk8+GVMUMkVqnbs+U1V6tTWeS8518Zp4zgZWzitwcZRZ5vuc6jbYsB+2cA62fb1rr8wU32ZnmbXaK504is6mrdF5WQU80wuDDA...HIS4DD6o6iU6Zy6Bi2dbuBbisUX+ZMq3zQu7UM2JAwcg53F5Vvmtw16yVlqsiqU48+Sy5pg2Qxrvf2T63kaZi0G+5K2ujfH....IYBmf3TgjReypZL8tOb1JxWIwcvmd4NaLsNpDfWThV80m+GZc23Es+Gxv189r+XRdC6ukK3Jq3lCj8or9xJQy1gtV6vxq6Fqytcncdj95mmXUMu2Mbw94tRPeqqCKAQ....RxDHAw1qfZkPTecEDf0Qkz4hRPr1OO6aFJIaTGmPMGNNcVecXeO4vRkvTMdkzzzPeee7crqc2Fdnb9tkYnck+rH65ZGeSoth2twW922I+9jfH....IYBjfH.qpwdWJ8W+q+4j75ZtEn6sn82xk8821it8+dRRdxOzu1O0Nqp6m09V7PgtMb+PckSb3S2N62umW0quqqDrkcd4ccsIJAQ....RhDDYhnVQuwpgd2EquXQ0b37tEay9NIqlc0qKW2DXFZpW+UcO0JYhwRsMw5oNeV87e6te3XIAwkopwVuOX2viySKRPD...fjLgSPrV4o6NRuFwuSy8uatg61dC0UPZU2WCqZzZnYnruMR+x7ZtbKk7109fltE2WuU9wOYTccu1G+s5pci8tSZc+bnz8XOuF6IhuozWe8P6i6UI693mcbR17etLlouWygaKKae68rRBh....jjIbBhsMTSFqsZkVAVci88E05JJnTqfcc6k+huYmOl5Rse7.5CZmH1gub0RBYre7qgl8tvrmOptJakvScb1cc2nbnaQIpW0hakL6u6+2.o2LTudoukrrDDA...HIRPbtZkHN7amVW6xiU0Jw73mMM5lab9rn8+vad02KII2+o+zNeLsIMulXZz9JlXQ0xyPYEXWWpYW5iV28g040djDo5DU2is8mynN955dkoMVtR11zpWeWIpWuOoNN9i+xSOAw9t59Q8799Wb0RPbWckBJAQ....RhDDYjxJwwaxhV421pZCXrqVQx69vmep+8.+da6t.LCK80tpJ8Sm0ZGdW85LIHB...PRlPIH19ZXFX5ppQ0UsVeneYYI.eVqAHnOa+VceX5WFq0rcWaYOtVue3EMI4Wmen96uyHc+NeaSBh....jjITBhi8U1YWuR4KZeooqM1SLXre+qu5fl8Mu6+zYWABRdb0rspgy40twhRPbje79ypZeYqbf8CxAk1c8P5GpDqZ2snYyn5VoKJIvJY8CaN+7dGO67C06SpZo+ImwtZ+l57XqZuOnuPBh....jjITBhiU0JjL02GjpUlodbXr18IkLR2nde1kt35sOkM00WR5npEkw1wIW2iy099+ptuaArXm28ix6HI+spJgwyZBhmW8kyCttjfH....IQBhLvIAU1kpUhz9c0vhmuXJoRLenjbwh5oA6+mlFuuspwNdyjz5tkDDA...HIivDD6pULqpMr9VW8DX5ZnjfvYUU6wpIzws95qiqj55ackv95iWqpZ7KYM9sVVx3tRx1rjfH....IYLlfXqt7nUVFXYFqcmzpFdFaqrZcb9q0jf3cWv9i0X0xpEG0J63h8YOX4IiW+65NyaFRPD...fjLBSPDVG09HlZcXZqRXqRb4xew2zkCGVhKMvqwpEYQcyw1piWol2Gmt2m8gm3quVq84W5V2ri2W8fcAIHB...PRjf3uyy+7OtqGBrCUqX+Puquw5oVI96loUsqw10483Hm2tgc6jvA17p2e8BI3uQUOtd3S+wNdjPhDDA...ngDDaLVqoEf0mZ8YXp51iSUtRHFlZ280KGzzsZ87JSA27puWRRd7yNNIa9Zrda89o1+7ZOtWz6u66jfH....IQBhCd09bFmtksegAml1cQP52pDeqUf9tOTskx12l5JMXuK9NK3ueXl7v557V6sCE97Zcqs06mpW+VuO9vW9im322it8Gkjja7keWRFN0HtDDA...HISvDDqZTYrrxbpcxSW87q82PX0csOXZWCePWnRfXp99u4InNx2WA84QF1V08o1wBIHB...PRl.IHV0RzS9gYqL0htV+ggfplWFKIfS+ht2J++2d287FUYYqAfeGoI.m4xQ3HJTgTK5LP3DRrmI.9K3L6N75zaHAl9GvDgTOglNq+KLDbMDynYxtiZoqk8DQlgrlLtAUsgA2.9qpp84rOOOIFjZZVlx0Gqy6Ys1r7syrYRxqqCcOC0mWJAQ....Rx.HAQnO6rW4JWo4qmC26dIw+905ZkjPG5mqiEsxim.smxmK6UM1LzJAQ....RRCkfnDA.9ZJIwHIh1vYe89+8oS+8kGeakGmG5yLuDToKqr0YGOZX+7zqpg1VAsuQBh....jjVJAwQRPD3KanmDSqp0RLjOmyMN5x75NzxjfH....IoGlfXYlDdYissf.t9N6LKMTecByjc+fYvYXwi2vmr+ildGB7yu9MUtRtXVfoqhG..Hw2IQTPTIIF+7S6G060kDDA...HI8vDDKm2HmWx.kYWnzw+q9+FlIIzJNujiKaSLnOYQM6z69f0WH++kusx1L7hdmtbcuhzkDoN9IO7J8muqRB3.TWRPD...fjzCSP7hx1kZwpV2K1m87r6j299O622ZJ2i9+3KNtxUBKB2RRIMkRxWm2c5R4+Naea32q0RDmqlC26d0tDFzjfH....IogSPj1VI4kRBhsJyhyhkDbXQnUuiF9ZJydIWL1loeYd+Nn6PBh....jDIHlc13l0tD3BnbE4e4QusxUBsjC2690tDnAIID9VFZmmZvkQe8N6oryHddO4bc77HAQ....Rx.JAwu1LqMzlUD..pmC19tIwcDCzhdZIIw+d+NIQIHB...PR5gIHZ1N5F5q2i3PKpb9f90N28.pOuu4WVY1sd4eUhpcYKq63twq0O2Jxm8bvUBh....zD5eIH57VZPojLxl2ojPhqvHbVeZK+JAwVRIwI24LsgylLhcf.76UlQWpKIHB...PR5gIHdVkqrZ4Jycxo+VMKGly9Z2K56N6d7t70Zo7yemb56Om+Kol1bVRzPWPI4nacNICt+iu8xnbnRjTBPWkDDA...HIMPBhkqD6Nabyjj7i+siqY4.zgTlg0ZmzLCamcKyVd+px6e8iuv6a0G8o6fI2IIvE0YedyAa+8e1uuUb7SdXsKgqEIHB...PRZfDDunJWoVaMLftBudD.Ss6CbmdLDz5ed7VIITIHB...PRFPIH1JczC..0RI4mme5alK++q74yr0doKqrMze9q+7etuU6uPBh....jjFLAwV8dZF3xyqG.cO15m8aksv6YSRAncHAQ....RRCkfXquUj.t717NqV6RnJt0YNmona3h93wG9K+4Ebkzss+ilNKZd+71lWeZX5fsuasKAt.jfH....IogRPr0c1qzV47BZ2MbtAACUesq.uWWnaY7ZqjjjSdqYt6ao7yyRNDf5RBh....jjkPBhW16wba2rurwiJyTzzqD8sFn269txxvm34CP2mD8g184AiGsRsKgEBIHB...PRVBIH5Jby7vPaK0t0joaeyV8JSMuUtyCNbu6mjj+zO8OpY4TMs5UnE.5mJedlg91K8re90t9LoKAQ....RRCrESKyl2PwlkjkZzYPrbkld4QuqxURcUl0zV8wYVLF5WgV.fkgwWxya38e7zy20m+52jDIHB...POQuOAwgFyXDPq6oO51e9u+EGWoJY4pbElAftsq5cvXYVD65eddIHB...PRVhIHZ1xnEUtBRN2NAttr0hAns0W1sDRPD...fjrTSPb58bqDDAVzNX6uOI8mqTG..zUHAQ....RxRLAwMuyzYPLuXY82Hr3UNuBijw6TjbH..b0HAQ....RRG9bPrj.vPa6Pd3d2KII+vu7uRxv66e9x18Ac6yKGXYnrMrKyzN..yeRPD...fjzgSPjo1cioIGcxo+VkqjECyJ1Ey9O910tDfp6iy7K..KLRPD...fjHAwNuMmMyMsZBhL0PclaAFtZ8W2qLyrk2G+U110.8DRPD...fjHAQnS3iakwI0sN.f4CyLKPekDDA...HIRPD5DFOZ5r3bqYyjiYUAXnw4aI.cCRPD...fjHAQ.XAqrMGe40LY7c13lyixYoo78MWLGr8cqcI.LmYVb6mjfH....IQBhzQr6CVOIIu7n2V4JA5OJmuZkyStVU46OynF.vhmDDA...HIMPBhadGy3QKn73nDDgKtRhZsdBhPeV44o6tw5UtR.tpJO+8me8apbkrbHAQ....RRCjfnYRAFdJIlcxouuxUBvUUY1ye5KNtxUxhkD9A5ajfH....IoARPr0Y1EnEMdz78bQx4mF8Iy6e9uuY7noIps+iucRZ+DDAnuQBh....jjNXBhkqr3Iu0rEAbwXVj62NuYzxiucaW2Yr6v8t2bpR.X4X7Zs8cBhDDA...HIcvDDA.9OUtyRnM02SH9i24S1pxWH1pqP2mDDA...HIRPjkrxUNrUl0zc13lII44u9MUtRf1yNy1dyRbf9nMmrZsKgNkxyiKIF+xidaMKG3Jo7yu88O+54QBh....jDIHxRVI4vC196SRxe5u9OpY4.cZO8QC6yINIGBsi99rlBII2Zs13Nf67HAQ....RROHAwcmMCJlwqgkC19tII4UG8tJWI...LbHAQ....RROHAQm+U.m0tOX5cVvPc17nep7ys..cYRPD...fjzCRPbnx19BnULdsUl9KF3yT79O910tD..NWRPD...fjHAwNqxV7rq5VNexnCv4jW+vkcVx27NqtfpDfZo75.s94GGzBjfH....IoGkf3VSldEkkXPaoqmT5xV4mue0QUtP53JILMzmoqV80CGOZkZWBbELTO2hKuNzK+o+YkqD.lOjfH....IoGkf3G2BdzDJIeT95KO5s0rb5LJauVaw1uM+6CPWgWOBn0HAQ....RROJAwVWIIsV6JQdUmQpxet+8os4LVAWEkmWr6CVuxUB..sJIHB...PRjfXmwk8bBq0MzlEOmqjbQTd9vPe6sBcYmcF6Ypy99bG9ec+JUIvU2PYayKAQ....RRESP75ddIc3d2adVN..v01P6Nf4hp749f9rgxyukfH....IoCNChkNxe9e+amrXq24Nssx8v9Im99JWI.v7fYNjg.e9kgAIHB...PR5fIHZaNxPP4br6ou33JWI.v7fsQNPqPBh....jjNXBhvPvl2Y0jjr6aGla0sydNgYVF..ftAIHB...PRVhIHNdzJWo+bkYR7j2JggtHI.c8r+itcsKA.Vn79D.zuHAQ....RxxLAwq31IsbdGt6FCyY0pqp73osw40iyMK..ftDIHB...PR5vawzRxgzMUd7o7UIHByeksc6SyzYU0rXCceNODA2gT8cRPD...fjzASP7iy11F2sxUBKSksb69O1V8DJJOu3j0llbnDDoOq7966z36TfRx+.zWIAQ....RRWLAwq34kXsUR95k+z+rxUR+T4JK6dVG98Jy5qmezlN9IOr1kvRQY17rUxAnaSBh....jjNTBhRPBfuLu9X+1NabyZWB..WXRPD...fjzgRPDfyyPIAsxLZMT99sUU1Vm80YqG.FljfH....IQBh.8HGrcae9nVRLr0+9bnv15D.5ijfH....IQCh....LiFDA...HIlAQXoXqIqV6R...fykDDA...HIZPDfp63m7vb7SdXsKC..PCh....LkYPrRJmyY+vu7upbkv0w3QqjDOdxUS4bO7jSe+ze+naTyxoZ1ZxnjLb+9G.nKQBh....jDIHxRx9O51II4me8apbkLeUR.Z7ak7AWckeN5v8tekqj5n75Ck+c.5i1+wS+43Rh3.zWIAQ....RhDDYIQx.S8oYsZkJWIP840EZaCsGekbHPqPBh....jjNPBhaMY0jjbxaeekqDXwqLiJ..CA6tw50tD.tjjfH....IohIHd1y6JIH1uc1yyM..XyY2oXLLU1R0zuHAQ....RRGXFDKr8u..ftMedMn8IAQ....RRGJAwyNShCMs1UjanscZctFB.7I1doP+kDDA...HIcnDDGZJa8yxWc930VrUWgymsaG.8Kk63sme5apbkvhjDDA...HIRPrZLyZ.CclQI.5WF56LjgBIHB...PRzfH....ynAQ....RRGZFDu0ZtmlA9b1Fr..8OlUw9MIHB...PR5PIHBvYs6CltkKe5KNtxUB..mmslrZRRNbu6W4JgqCIHB...PRjfHrPTt26M6b.CckWObGm6k.zKHAQ....RhDDA5A1cVxCaMYTkqDtJrkpG1Fu1JI4SOOF.51jfH....IQBh.8.NOk52j76vT4w8C19tUtR.fKCIHB...PRzfHKHaMYjTC.X.a7naH8e.5gzfH....IwLHB..LmsyF2LIIiGsRkqDfKKIHB...PRjfH..vbl8P.zeIAQ....RhFDA...XFMHB...PRLChrfbq0b1WA..PeiDDA...HIRPj4rslr5ruNc6k8i43ZVN...vkfDDA...HIRPD..XN4v8tWsKAfqIIHB...PRjfHKYkYSD.f1i2mG5+jfH....IQBhyMiGsRR9zV77kG8tZVNcNkqnnqrH...cWRPD...fjzARPb+Gc6jjLdsaT4J45oT+iWaZRh4BlfnD0...ftBIHB...PRpXBhadmoypWeO4vqpx22Gr8cqbk....LkDDA...HIULAwVc16JyT4ye8apbkPWxg6c+ZWB...btjfH....IQCh....LiFDA...HIZPD...fYzfH....IQCh.Uz3Q2HiGMLOKTA.ftHMHB...PRp34f3P030jVB...zMIAQ....RRERPbqIqtr+qrSY2GrdsKA...fuHIHB...PRpPBhGt28W1+UBUywO4g0tD...3BSBh....jDawTXgX7ZqL6q1Zs...8GRPD...fjnAQ....lQCh....jDyfH...bAr4clcdl+h5VGrXIAQ....RhFDA..th1ci0ytardsKCpjslrZ1Zxp0tLXNSCh....jDyfH..vUz3QNuegViDDA...HIZPD...fYzfH....IQCh....LiFDA...HIZPD...fYzfH....Iw4fHyYiWakZWB...vUjDDA...HIRPDnCamMVOIIiW6FUtR..3qYqIqV6Rf4HIHB...PRjfHPGljCA.5tJ6dhc13lII4G+aGWyxg4DIHB...PRjfHyI6+namjjWcz6pbk....WURPD...fjHAQVv1ZxnZWB...vEjDDA...HIRPjEjx1m7fsuakqD...3hRBh....jDIHB..bMs6FqW6R.XNQBh....jDIHtzsiqvF..MlwitQsKAf4DIHB...PRjf3RWY6dB...z0HAQ....RhDDAfkL2IE..cWRPD...fjHAQ.XIaqIipcI..yA1dssIIHB...PRzfH....ynAQ....RhYPD..3R53m7vjj7yu9MUtR.l2jfH....IQBh..LGUNmK2Yi0qbkvhjyyT9OMdzJIwy6aERPD...fjHAQ..liJmKZRXBFNJOee20jfXKPBh....jDMHB...vLZPD...fjnAQ....lQCh....jDMHB...vLZPD...fj3bPDnCobNJcxouuxUB..m03QqT6Rfk.IHB...PRjfHPGx3QRPD.nqpbm9PaSBh....jDMHB...vLZPD...fjXFDA.XNXyIqljjSN82pbk..WGRPD...fjHAQfJ5fs+9jj7C+x+akqD..fDIHB...vLRPDnZbdJA.zecKuOdSRBh....jDIHB...WA6tw50tDXAPBh....jDMHB...vLZPD...fjnAQ....lQCh....jDawzEtslrZRRd4QuqxUB..Les4cVs1k.vblDDA...HIRPbgaqIiRhDDGJNX66ljjW4wa.X.n74b.ZGRPD...fjHAwklxrHRaZ7Z2X5u3n5VG...bcHAQ....RhDDWZNbu6W6R....3aRBh....jDMHB...vLZPD...fjXFDA5PFu1JS+ENGIA.fpPBh....jDIHxbxGOG.iy6Q...5qjfH....IQBhLmr0jQS+ESpac..0wmtSR.f9LIHB...PRzfH....ynAQ....RhYPDlqJyh4GmIS...5QjfH....IQBhvbks3G70cv12MIIu5n2U4JA.fuFIHB...PRjfHPGv30Vo1k.KPeLY8ipac..v4SBh....jDIHBzAr4jUShYSC5yFOZ5cBv9O91UtR.fqCIHB...PRjfHPGPYF0dkYTC5sJOO11bFf9MIHB...PRjfHPGvVSF8Ye8jS+sZVN..vfkDDA...HIRPDnC5v8tesKA..XPRBh....jDMHB...vLZPD...fjnAQ....lQCh....jDMHB...vLZPD...fjnAQ....lQCh....jDMHB...vLZPD...fjj7GqcAz51+w2t1k....vEhDDA...HIRPbgY7Z2n1k....vkhDDA...HIZPD...fYzfH....IQCh....LiFDA...HIZPD...fYzfH....Iw4fH.rjr0jQ0tD..3bHAQ....RhDDAfkjwqcijjr6ZqW4JA.fuFIHB...PRzfH....ynAQ....RhFDA...XFMHB...PRrESWXFO5F0tD....tTjfH....IQBhycky4qC269UtR....tbjfH....IQCh....LiFDA...HIZPDfNmm8rmkm8rmU6x..tj752zBzfH....II4O7gO7gOT6h..9ju669tjj7q+5uV4JA.tLFJu98e3+9+IIIe3u7mqbkvhfDDA...HIZPD...fYzfH....II4OV6B....5O1Zxp0tDXARBh....jDIHB...WBGt28qcIvBjDDA...HIZPD...fYzfH....IQCh....LiFDA...HII++z8IkGE8fRIC.....jTQNQjqBAlf" ],
					"embed" : 1,
					"id" : "obj-4",
					"maxclass" : "fpic",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "jit_matrix" ],
					"patching_rect" : [ 552.000061, 182.057693, 348.599915, 414.12384 ],
					"pic" : "segments.png"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-2",
					"linecount" : 3,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 9.0, 127.0, 894.0, 50.0 ],
					"style" : "",
					"text" : "Orchidea is able to perform dynamic orchestration, in order to follow a time evolving target. The basic principle is to cut a dynamic target into static segments. The current segmentation model uses thresholds and timegates on specific spectral features to determine onsets. Timegates are specified in seconds, thresholds are absolute values between 0 and 1."
				}

			}
, 			{
				"box" : 				{
					"angle" : 270.0,
					"bgcolor" : [ 0.878431, 0.878431, 0.843137, 1.0 ],
					"id" : "obj-20",
					"maxclass" : "panel",
					"mode" : 0,
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 9.0, 62.0, 131.0, 35.235489 ],
					"proportion" : 0.39,
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.878431, 0.878431, 0.843137, 1.0 ],
					"fontname" : "Arial",
					"fontsize" : 45.0,
					"id" : "obj-67",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 227.0, 20.735489, 458.0, 57.0 ],
					"style" : "",
					"text" : "Dynamic orchestration",
					"textjustification" : 1
				}

			}
, 			{
				"box" : 				{
					"border" : 3.0,
					"id" : "obj-15",
					"linecolor" : [ 0.011765, 0.396078, 0.752941, 1.0 ],
					"maxclass" : "live.line",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 9.0, 59.0, 894.0, 16.442019 ]
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.878431, 0.878431, 0.843137, 1.0 ],
					"fontname" : "Arial",
					"fontsize" : 79.949177,
					"id" : "obj-19",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 9.0, 1.235489, 77.0, 96.0 ],
					"style" : "",
					"text" : "2",
					"textcolor" : [ 0.011765, 0.396078, 0.752941, 1.0 ],
					"textjustification" : 1
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-39", 0 ],
					"hidden" : 1,
					"source" : [ "obj-11", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-11", 0 ],
					"hidden" : 1,
					"source" : [ "obj-13", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-9", 0 ],
					"source" : [ "obj-14", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-9", 0 ],
					"source" : [ "obj-16", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-9", 0 ],
					"source" : [ "obj-17", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-51", 0 ],
					"source" : [ "obj-23", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-23", 0 ],
					"midpoints" : [ 20.5, 817.666672, 403.0, 817.666672 ],
					"order" : 0,
					"source" : [ "obj-24", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-29", 0 ],
					"order" : 1,
					"source" : [ "obj-24", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-31", 0 ],
					"source" : [ "obj-26", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-24", 1 ],
					"source" : [ "obj-28", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-38", 0 ],
					"source" : [ "obj-29", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-24", 0 ],
					"order" : 1,
					"source" : [ "obj-30", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-26", 0 ],
					"midpoints" : [ 20.5, 747.666687, -3.333313, 747.666687, -3.333313, 816.666687, 269.0, 816.666687 ],
					"order" : 0,
					"source" : [ "obj-30", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-41", 1 ],
					"order" : 0,
					"source" : [ "obj-34", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-41", 0 ],
					"order" : 1,
					"source" : [ "obj-34", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-42", 0 ],
					"source" : [ "obj-36", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-36", 0 ],
					"order" : 1,
					"source" : [ "obj-38", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-6", 0 ],
					"order" : 0,
					"source" : [ "obj-38", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-41", 1 ],
					"order" : 0,
					"source" : [ "obj-42", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-41", 0 ],
					"order" : 1,
					"source" : [ "obj-42", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-36", 0 ],
					"order" : 1,
					"source" : [ "obj-43", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-6", 0 ],
					"order" : 0,
					"source" : [ "obj-43", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-24", 2 ],
					"source" : [ "obj-45", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-28", 0 ],
					"order" : 1,
					"source" : [ "obj-47", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-30", 0 ],
					"order" : 2,
					"source" : [ "obj-47", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-45", 0 ],
					"order" : 0,
					"source" : [ "obj-47", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-34", 0 ],
					"source" : [ "obj-6", 0 ]
				}

			}
 ],
		"parameters" : 		{
			"obj-42" : [ "solution", "solution", 0 ],
			"obj-34" : [ "target", "target", 0 ]
		}
,
		"dependency_cache" : [ 			{
				"name" : "segments.png",
				"bootpath" : "~/MusicaMia/_RICERCA/orchidea/max/media",
				"patcherrelativepath" : "../../media",
				"type" : "PNG ",
				"implicit" : 1
			}
, 			{
				"name" : "orchidea.solution.totext.maxpat",
				"bootpath" : "~/MusicaMia/_RICERCA/orchidea/max/patchers",
				"patcherrelativepath" : "../../patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "orchidea.solution.tobuffer.maxpat",
				"bootpath" : "~/MusicaMia/_RICERCA/orchidea/max/patchers",
				"patcherrelativepath" : "../../patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "orchidea.db.tinySOL.maxpat",
				"bootpath" : "~/MusicaMia/_RICERCA/orchidea/max/patchers",
				"patcherrelativepath" : "../../patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "continuity.png",
				"bootpath" : "~/MusicaMia/_RICERCA/orchidea/max/media",
				"patcherrelativepath" : "../../media",
				"type" : "PNG ",
				"implicit" : 1
			}
, 			{
				"name" : "orchidea.solve.mxo",
				"type" : "iLaX"
			}
 ],
		"autosave" : 0
	}

}
