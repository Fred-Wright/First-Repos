using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Preview : MonoBehaviour
{

    public GameObject prefab;

    private MeshRenderer myRend;
    public Material goodMat;
    public Material badMat;

    private BuildSystem buildSystem;

    private bool isSnapped = false;

    public bool isFoundation = false;

    public List<string> tagsISnapTo = new List<string>();//list of all of the SnapPoint tags this particular preview can snap too
                                                         //this allows this previewObject to be able to snap to multiple snap points

    private void Start()
    {
        buildSystem = GameObject.FindObjectOfType<BuildSystem>();
        myRend = GetComponent<MeshRenderer>();
        ChangeColor();
    }

    public void Place()
    {
        Instantiate(prefab, transform.position, transform.rotation);
        Destroy(gameObject);
    }

    private void ChangeColor()//changes between red and greed depending if this preview is/is not snapped to anything
    {
        if (isSnapped)
        {
            myRend.material = goodMat;
        }
        else
        {
            myRend.material = badMat;
        }

        if (isFoundation)//this is the foundation rule that was added earlier
        {
            myRend.material = goodMat;
            isSnapped = true;
        }


    }

    private void OnTriggerEnter(Collider other)//this is what dertermins if you are snapped to a snap point
    {
        for (int i = 0; i < tagsISnapTo.Count; i++)
        {
            string currentTag = tagsISnapTo[i];

            if(other.tag == currentTag)
            {
                buildSystem.PauseBuild(true);

                transform.position = other.transform.position;//set position of preview so that it "snaps" into position
                isSnapped = true;
                ChangeColor();
            }

        }
    }

    private void OnTriggerExit(Collider other)//this is what determins if you are no longer snapped to a snap point
    {
        for (int i = 0; i < tagsISnapTo.Count; i++)
        {
            string currentTag = tagsISnapTo[i];

            if(other.tag == currentTag)
            {
                isSnapped = false;
                ChangeColor();
            }
        }
    }


    public bool GetSnapped()
    {
        return isSnapped;
    }




}
