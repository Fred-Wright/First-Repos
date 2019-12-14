using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BuildSystem : MonoBehaviour {


    public Camera cam;
    public LayerMask layer;

    private GameObject previewGameObject;
    private Preview previewScript;

    public float stickTolerance = 1.5f;

    [HideInInspector] //hiding this in inspector, so it doesnt accidently get clicked
    public bool isBuilding = false;
    private bool pauseBuilding = false;



    private void Update()
    {
        if (Input.GetKeyDown(KeyCode.R))//rotate
        {
            previewGameObject.transform.Rotate(0, 90f, 0);//rotate the preview 90 degrees. You can add in your own value here
        }

        if (Input.GetKeyDown(KeyCode.G))//cancel build
        {
            CancelBuild();
        }

        if (Input.GetMouseButtonDown(0) && isBuilding)//actually build the thing in the world
        {
            if (previewScript.GetSnapped()) 
            {
                StopBuild();
            }
            else
            {
                Debug.Log("Not Snapped");//this part isn't needed, but may be good to give your player some feedback if they can't build
            }
        }

        if (isBuilding)
        {
            if (pauseBuilding)
            {
                float mouseX = Input.GetAxis("Mouse X");
                float mouseY = Input.GetAxis("Mouse Y");

                if (Mathf.Abs(mouseX) >= stickTolerance || Mathf.Abs(mouseY) >= stickTolerance)
                {
                    pauseBuilding = false;
                }

            }
            else
            {
                DoBuildRay();
            }
        }
    }

    public void NewBuild(GameObject _go)
    {
        previewGameObject = Instantiate(_go, Vector3.zero, Quaternion.identity);
        previewScript = previewGameObject.GetComponent<Preview>();
        isBuilding = true;
    }

    private void CancelBuild()//you no longer want to build, this will get rid of the previewGameObject in the scene
    {
        Destroy(previewGameObject);
        previewGameObject = null;
        previewScript = null;
        isBuilding = false;
    }

    private void StopBuild()//This is a bad name, It should be called something like BuildIt(). This will actually build your preview in the world
    {
        previewScript.Place();
        previewGameObject = null;
        previewScript = null;
        isBuilding = false; 
    }

    public void PauseBuild(bool _value)//public method to change the pauseBuilding bool from another script. Preview.cs calls this 
                                       //method whereever it snaps to a snap point
    {
        pauseBuilding = _value;
    }

    private void DoBuildRay()//actually positions your previewGameobject in the world
    {
        Ray ray = cam.ScreenPointToRay(Input.mousePosition);//raycast stuff
        RaycastHit hit;

        if(Physics.Raycast(ray,out hit, 100f, layer))
        {
            float y = hit.point.y + (previewGameObject.transform.localScale.y / 2f);
            Vector3 pos = new Vector3(hit.point.x, y, hit.point.z);
            previewGameObject.transform.position = pos;
        }
    }

}
