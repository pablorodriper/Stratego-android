struct ClassRegistrationContext;
void InvokeRegisterStaticallyLinkedModuleClasses(ClassRegistrationContext& context)
{
	// Do nothing (we're in stripping mode)
}

void RegisterStaticallyLinkedModulesGranular()
{
	void RegisterModule_Audio();
	RegisterModule_Audio();

	void RegisterModule_CloudWebServices();
	RegisterModule_CloudWebServices();

	void RegisterModule_Physics();
	RegisterModule_Physics();

	void RegisterModule_Terrain();
	RegisterModule_Terrain();

	void RegisterModule_TerrainPhysics();
	RegisterModule_TerrainPhysics();

	void RegisterModule_UnityAnalytics();
	RegisterModule_UnityAnalytics();

	void RegisterModule_UnityConnect();
	RegisterModule_UnityConnect();

	void RegisterModule_UnityWebRequest();
	RegisterModule_UnityWebRequest();

}

void RegisterAllClasses()
{
	//Total: 63 classes
	//0. GUILayer
	void RegisterClass_GUILayer();
	RegisterClass_GUILayer();

	//1. Behaviour
	void RegisterClass_Behaviour();
	RegisterClass_Behaviour();

	//2. Component
	void RegisterClass_Component();
	RegisterClass_Component();

	//3. EditorExtension
	void RegisterClass_EditorExtension();
	RegisterClass_EditorExtension();

	//4. Texture
	void RegisterClass_Texture();
	RegisterClass_Texture();

	//5. NamedObject
	void RegisterClass_NamedObject();
	RegisterClass_NamedObject();

	//6. Texture2D
	void RegisterClass_Texture2D();
	RegisterClass_Texture2D();

	//7. NetworkView
	void RegisterClass_NetworkView();
	RegisterClass_NetworkView();

	//8. RectTransform
	void RegisterClass_RectTransform();
	RegisterClass_RectTransform();

	//9. Transform
	void RegisterClass_Transform();
	RegisterClass_Transform();

	//10. Camera
	void RegisterClass_Camera();
	RegisterClass_Camera();

	//11. MonoBehaviour
	void RegisterClass_MonoBehaviour();
	RegisterClass_MonoBehaviour();

	//12. GameObject
	void RegisterClass_GameObject();
	RegisterClass_GameObject();

	//13. Collider
	void RegisterClass_Collider();
	RegisterClass_Collider();

	//14. AudioClip
	void RegisterClass_AudioClip();
	RegisterClass_AudioClip();

	//15. SampleClip
	void RegisterClass_SampleClip();
	RegisterClass_SampleClip();

	//16. PreloadData
	void RegisterClass_PreloadData();
	RegisterClass_PreloadData();

	//17. Material
	void RegisterClass_Material();
	RegisterClass_Material();

	//18. Cubemap
	void RegisterClass_Cubemap();
	RegisterClass_Cubemap();

	//19. Texture3D
	void RegisterClass_Texture3D();
	RegisterClass_Texture3D();

	//20. Texture2DArray
	void RegisterClass_Texture2DArray();
	RegisterClass_Texture2DArray();

	//21. RenderTexture
	void RegisterClass_RenderTexture();
	RegisterClass_RenderTexture();

	//22. Mesh
	void RegisterClass_Mesh();
	RegisterClass_Mesh();

	//23. LevelGameManager
	void RegisterClass_LevelGameManager();
	RegisterClass_LevelGameManager();

	//24. GameManager
	void RegisterClass_GameManager();
	RegisterClass_GameManager();

	//25. TimeManager
	void RegisterClass_TimeManager();
	RegisterClass_TimeManager();

	//26. GlobalGameManager
	void RegisterClass_GlobalGameManager();
	RegisterClass_GlobalGameManager();

	//27. AudioManager
	void RegisterClass_AudioManager();
	RegisterClass_AudioManager();

	//28. InputManager
	void RegisterClass_InputManager();
	RegisterClass_InputManager();

	//29. MeshRenderer
	void RegisterClass_MeshRenderer();
	RegisterClass_MeshRenderer();

	//30. Renderer
	void RegisterClass_Renderer();
	RegisterClass_Renderer();

	//31. GraphicsSettings
	void RegisterClass_GraphicsSettings();
	RegisterClass_GraphicsSettings();

	//32. MeshFilter
	void RegisterClass_MeshFilter();
	RegisterClass_MeshFilter();

	//33. QualitySettings
	void RegisterClass_QualitySettings();
	RegisterClass_QualitySettings();

	//34. Shader
	void RegisterClass_Shader();
	RegisterClass_Shader();

	//35. TextAsset
	void RegisterClass_TextAsset();
	RegisterClass_TextAsset();

	//36. PhysicsManager
	void RegisterClass_PhysicsManager();
	RegisterClass_PhysicsManager();

	//37. MeshCollider
	void RegisterClass_MeshCollider();
	RegisterClass_MeshCollider();

	//38. BoxCollider
	void RegisterClass_BoxCollider();
	RegisterClass_BoxCollider();

	//39. TagManager
	void RegisterClass_TagManager();
	RegisterClass_TagManager();

	//40. AudioListener
	void RegisterClass_AudioListener();
	RegisterClass_AudioListener();

	//41. AudioBehaviour
	void RegisterClass_AudioBehaviour();
	RegisterClass_AudioBehaviour();

	//42. ScriptMapper
	void RegisterClass_ScriptMapper();
	RegisterClass_ScriptMapper();

	//43. DelayedCallManager
	void RegisterClass_DelayedCallManager();
	RegisterClass_DelayedCallManager();

	//44. RenderSettings
	void RegisterClass_RenderSettings();
	RegisterClass_RenderSettings();

	//45. Light
	void RegisterClass_Light();
	RegisterClass_Light();

	//46. MonoScript
	void RegisterClass_MonoScript();
	RegisterClass_MonoScript();

	//47. MonoManager
	void RegisterClass_MonoManager();
	RegisterClass_MonoManager();

	//48. FlareLayer
	void RegisterClass_FlareLayer();
	RegisterClass_FlareLayer();

	//49. PlayerSettings
	void RegisterClass_PlayerSettings();
	RegisterClass_PlayerSettings();

	//50. BuildSettings
	void RegisterClass_BuildSettings();
	RegisterClass_BuildSettings();

	//51. ResourceManager
	void RegisterClass_ResourceManager();
	RegisterClass_ResourceManager();

	//52. NetworkManager
	void RegisterClass_NetworkManager();
	RegisterClass_NetworkManager();

	//53. TerrainCollider
	void RegisterClass_TerrainCollider();
	RegisterClass_TerrainCollider();

	//54. MasterServerInterface
	void RegisterClass_MasterServerInterface();
	RegisterClass_MasterServerInterface();

	//55. TerrainData
	void RegisterClass_TerrainData();
	RegisterClass_TerrainData();

	//56. LightmapSettings
	void RegisterClass_LightmapSettings();
	RegisterClass_LightmapSettings();

	//57. Terrain
	void RegisterClass_Terrain();
	RegisterClass_Terrain();

	//58. LightProbes
	void RegisterClass_LightProbes();
	RegisterClass_LightProbes();

	//59. RuntimeInitializeOnLoadManager
	void RegisterClass_RuntimeInitializeOnLoadManager();
	RegisterClass_RuntimeInitializeOnLoadManager();

	//60. CloudWebServicesManager
	void RegisterClass_CloudWebServicesManager();
	RegisterClass_CloudWebServicesManager();

	//61. UnityAnalyticsManager
	void RegisterClass_UnityAnalyticsManager();
	RegisterClass_UnityAnalyticsManager();

	//62. UnityConnectSettings
	void RegisterClass_UnityConnectSettings();
	RegisterClass_UnityConnectSettings();

}
